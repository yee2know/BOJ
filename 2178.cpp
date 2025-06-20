#include <vector>
#include <queue>
#include <iostream>
using namespace std;
static vector<vector<bool>> visited;
static vector<vector<int>> A;
static bool arrive;
static int dx[] = {0,-1,0,1};
static int dy[] = {1,0,-1,0};
void BFS(int N,int M);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	visited = vector<vector<bool>>(N,vector<bool>(M,false));
	A = vector<vector<int>>(N,vector<int>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char a;
			cin >> a;
			A[i][j]=a-'0';
		}
	}
	arrive=false;
	BFS(N,M);
	cout << A[N-1][M-1];
	return 0;
}

void BFS(int N,int M){
	queue<pair<int,int>> B;
	B.push(make_pair(0,0));

	while(!B.empty()){
		int now[2];
		now[0]=B.front().first;
		now[1]=B.front().second;
		
		B.pop();
		for(int i=0;i<4;i++){
			int x = now[0]+dx[i];
			int y = now[1]+dy[i];
			if(x>=0&&y>=0&&x<N&&y<M){
			if(!visited[x][y]&&A[x][y]!=0){
				B.push(make_pair(x,y));
				A[x][y]=A[now[0]][now[1]]+1;
				visited[x][y] = true;
			}
		}
		}
	}
}