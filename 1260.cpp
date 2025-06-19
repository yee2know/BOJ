#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);
void BFS(int v);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M,Start;
	cin >> N >> M >> Start;
	A.resize(N+1);
	visited = vector<bool>(N+1,false);
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	for(int i=1;i<=N;i++){
		sort(A[i].begin(),A[i].end());
	}
	DFS(Start);
	cout << "\n";
	fill(visited.begin(),visited.end(),false);
	BFS(Start);
	return 0;
}

void DFS(int v){
	if(visited[v]) return;
	visited[v]=true;
	cout << v << " ";
	for(int k : A[v]){
		if(!visited[k]) DFS(k);
	}
}

void BFS(int v){
	queue<int> B;
	B.push(v);
	visited[v]=true;

	while(!B.empty()){
		int node = B.front();
		cout << node << " ";
		B.pop();
		for(int k : A[node]){
			if(!visited[k]) {
				B.push(k);
				visited[k]=true;
			}
		}

	}
}