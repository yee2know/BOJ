#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // 좌표 범위: x in [0, 2N], y in [0, N]
    const int XMAX = 2 * N;
    const int YMAX = N;

    // blocked[y][x] == true 면 해당 격자에 교사가 있어 방문 불가
    vector<vector<char>> blocked(YMAX + 1, vector<char>(XMAX + 1, 0));
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        blocked[y][x] = 1;
    }

    auto inside = [&](int x, int y) -> bool {
        if (x < 0 || x > XMAX || y < 0 || y > YMAX) return false;
        // 삼각형 조건: 0 <= y <= min(x, 2N - x)
        int top = (x <= N) ? x : (2 * N - x);
        return (y <= top);
    };

    // 시작/도착 지점에 교사가 없다는 건 보장됨 (문제 조건)
    // BFS1: (0,0) -> x+1, y±1
    vector<vector<char>> vis1(YMAX + 1, vector<char>(XMAX + 1, 0));
    if (!blocked[0][0]) {
        queue<pair<int,int>> q;
        vis1[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            int nx = x + 1;
            if (nx <= XMAX) {
                for (int dy : {+1, -1}) {
                    int ny = y + dy;
                    if (inside(nx, ny) && !blocked[ny][nx] && !vis1[ny][nx]) {
                        vis1[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    // BFS2: (2N,0)에서 역방향으로 x-1, y±1
    vector<vector<char>> vis2(YMAX + 1, vector<char>(XMAX + 1, 0));
    if (!blocked[0][XMAX]) {
        queue<pair<int,int>> q;
        vis2[0][XMAX] = 1;
        q.push({0, XMAX});
        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            int nx = x - 1;
            if (nx >= 0) {
                for (int dy : {+1, -1}) {
                    int ny = y + dy;
                    if (inside(nx, ny) && !blocked[ny][nx] && !vis2[ny][nx]) {
                        vis2[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    // (0,0)->(2N,0) 경로가 존재하는지 안전 체크
    if (!vis1[0][XMAX] || !vis2[0][0]) {
        cout << -1 << '\n';
        return 0;
    }

    // 두 BFS 모두에서 도달 가능한 점들 중 y의 최댓값
    int ans = -1;
    for (int y = 0; y <= YMAX; ++y) {
        for (int x = 0; x <= XMAX; ++x) {
            if (vis1[y][x] && vis2[y][x]) ans = max(ans, y);
        }
    }
    cout << ans << '\n';
    return 0;
}