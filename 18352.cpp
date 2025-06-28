#include <queue>
#include <vector>
#include <iostream>
using namespace std;
static vector<vector<int>> A;
static vector<int> visited;
void BFS(int v);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M,K,X;
	cin >> N >> M >> K >>X;
	A.resize(N+1);
	visited = vector<int>(N+1,-1);
	int t1,t2;
	for(int i=0;i<M;i++) {
		cin >> t1 >> t2;
		A[t1].push_back(t2);
	}
	BFS(X);
	bool isAnswer = false;
	for(int i=1;i<=N;i++){
		if(visited[i]==K){
			cout << i << "\n";
			isAnswer=true;
		}
	}
	if(!isAnswer) cout << -1;
	return 0;
}

void BFS(int v){
	visited[v]=0;
	queue<int> B;
	B.push(v);
	
	while(!B.empty()){
		int node = B.front();
		B.pop();

		for(int i : A[node]){
			if(visited[i]==-1){
				visited[i]=visited[node]+1;
				B.push(i);
			}
		}
	}
}