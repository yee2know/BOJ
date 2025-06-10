#include <iostream>
#include <vector>
using namespace std;
static int M,N;
static vector<vector<bool>> visited;

void DFS(int x,int y){
	if(visited[x][y]) return;
	visited[x][y]=true;
	if(x!=0) DFS(x-1,y);
	if(x!=M-1) DFS(x+1,y);
	if(y!=0) DFS(x,y-1);
	if(y!=N-1) DFS(x,y+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int K,count=0;
		cin >> M >> N >> K;
		visited = vector<vector<bool>>(M,vector<bool>(N,true));
		for(int i=0;i<K;i++){
			int a,b;
			cin >> a >> b;
			visited[a][b]=false;
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(!visited[i][j]) {
					DFS(i,j);
					count++;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}