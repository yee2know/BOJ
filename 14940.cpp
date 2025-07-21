#include <vector>
#include <iostream>
#include <queue>
using namespace std;
static int dx[] = {0,1,0,-1};
static int dy[] = {1,0,-1,0};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	int A[1001][1001]={0};
	int start[2];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
			if(A[i][j]==2){
				start[0]=i;
				start[1]=j;
			}
		}
	}
	queue<pair<int,int>> q;
	bool visited[1001][1001]={false};
	q.push(make_pair(start[0],start[1]));
	A[start[0]][start[1]]=0;
	while(!q.empty()){
		pair<int,int> now = q.front();
		q.pop();
		visited[now.first][now.second]=true;

		for(int i=0;i<4;i++){
			int y = now.first+dy[i];
			int x = now.second+dx[i];
			if(x>=0&&y>=0&&x<M&&y<N){
				if(!visited[y][x]&&A[y][x]==1){
					A[y][x]=A[now.first][now.second]+1;
					q.push(make_pair(y,x));
				}
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(A[i][j]==1&&!visited[i][j])
				cout << -1 << " ";
			else 
				cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}