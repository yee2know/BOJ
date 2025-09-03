#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct posInfo {
	int row;
	int col;
	int height;
};

int dRow[8] = { -1,-1,0,1,1, 1, 0,-1 };
int dCol[8] = { 0 , 1,1,1,0,-1,-1,-1 };

vector<vector<int>> board;
vector<vector<bool>> found;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	board = vector<vector<int>>(n, vector<int>(m));
	found = vector<vector<bool>>(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<posInfo> q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (found[i][j]) continue;
			found[i][j] = true;
			q.push({ i,j,board[i][j] });
			bool ans = true;
			while (!q.empty()) {
				auto curr = q.front();
				q.pop();

				for (int k = 0; k < 8; k++) {
					int nextRow = curr.row + dRow[k];
					int nextCol = curr.col + dCol[k];
					if (nextRow < 0 || nextRow >= n) continue;
					if (nextCol < 0 || nextCol >= m) continue;
					if (board[nextRow][nextCol] > curr.height) {
						ans = false;
						continue;
					}
					if (found[nextRow][nextCol]) continue;
					if (board[nextRow][nextCol] < curr.height) continue;
					q.push({ nextRow,nextCol,curr.height });
					found[nextRow][nextCol] = true;
				}
			}
			if (ans) cnt++;
		}
	}
	cout << cnt;
}