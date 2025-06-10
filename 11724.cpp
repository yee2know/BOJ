#include <iostream>
#include <vector>
using namespace std;
vector<vector <int>> A;
vector<bool> visit;
void DFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M,N,count=0;
	cin >> N >> M;
	A.resize(N+1);
	visit= vector<bool>(N+1,false);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	for(int i=1;i<=N;i++){
		if(!visit[i]){
			count++;
			DFS(i);
		}
	}
	cout << count;
	return 0;
}

void DFS(int v){
	if(visit[v]) return;
	visit[v] = true;
	for(int i : A[v]){
		if(!visit[i]) DFS(i);
	}
}