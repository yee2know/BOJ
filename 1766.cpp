#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int N, M;
vector<int> line[32001];
priority_queue<int, vector<int>, greater<int>> q;
int connect[32001];

void bfs() {
	while (!q.empty()) {
		int x = q.top();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < line[x].size(); i++) {
			connect[line[x][i]]--;
			if (!connect[line[x][i]]) {
				q.push(line[x][i]);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		line[x].push_back(y);
		connect[y]++;
	}
	for (int i = 1; i <= N; i++) {
		if (connect[i] == 0) q.push(i);
	}
	bfs();
	return 0;
}