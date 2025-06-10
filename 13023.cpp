#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static vector<int> relations;
static int answered=0;

void DFS(int v,int depth){
	if(depth==5) {answered=1; return;}
	visited[v]=true;
	for(int i : A[v]){
		if(!visited[i]) {
			DFS(i,depth+1);
		}
	}
	visited[v]=false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	A.resize(N+1);
	visited = vector<bool>(N+1,false);
	relations = vector<int>(N+1,0);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	for(int i=1;i<N+1;i++){
		DFS(i,1);
		if(answered) break;
	}
	if(answered) cout << 1;
	else cout << 0;
	return 0;
}