#include <vector>
#include <iostream>
using namespace std;
static int N,M;
static int cnt;
static vector<vector<int>> A;
static vector<vector<bool>> visited;
static int dx[] = {-1,0,1,0};
static int dy[] = {0,-1,0,1};
void DFS(int a,int b){
	visited[b][a]=true;
	cnt++;
	for(int i=0;i<4;i++){
		int x = a+dx[i];
		int y = b+dy[i];
		if(x>=0&&y>=0&&x<M&&y<N){
			if(!visited[y][x]&&A[y][x]==1){
				DFS(x,y);
				
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	A = vector<vector<int>>(N,vector<int>(M,0));
	visited =  vector<vector<bool>>(N,vector<bool>(M,false));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int t;
			cin >> t;
			if(t==1) A[i][j]=1;
		}
	}
	int counter=0;
	int max=-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!visited[i][j]&&A[i][j]==1){
				cnt=0;
				DFS(j,i);
				if(max<cnt)max=cnt;
				counter++;
			}
		}
	}
	cout << counter << "\n" << max;
	return 0;
}