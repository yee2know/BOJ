#include <vector>
#include <iostream>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
static int virus=0;
void DFS(int v);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	A.resize(N+1);
	visited = vector<bool>(N+1,false);
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	DFS(1);
	cout << virus;
	return 0;
}

void DFS(int v){
	visited[v]=true;

	for(int i : A[v]){
		if(!visited[i]) {DFS(i);virus++;}
	}
}