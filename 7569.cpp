#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static int dx[]= {0,-1,0,1,0,0};
static int dy[]= {1,0,-1,0,0,0};
static int dz[]= {0,0,0,0,1,-1};
static vector<vector<int>> A;
static int totalCount;
void BFS(vector<pair<int,int>> B,int M,int N,int H);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M,H;
	cin >> M >> N >> H;
	totalCount = M*N*H;
	vector<pair<int,int>> B;
	A = vector<vector<int>>(N,vector<int>(M));
	for(int i=0;i<N*H;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
			if(A[i][j]==-1) totalCount--;
			else if(A[i][j]==1) B.push_back(make_pair(j,i));
		}
	}
	BFS(B,M,N,H);
	if(totalCount==0){
		int max=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(max<A[i][j]) max = A[i][j];
			}
		}
		cout << max-1;
	}else{
		cout << -1;
	}
	return 0;
}

void BFS(vector<pair<int,int>> B,int M,int N,int H){
	queue<pair<int,int>> MyQueue;
	for(int i=0;i<B.size();i++){
		MyQueue.push(make_pair(B[i].first,B[i].second));
		totalCount--;
	}

	while(!MyQueue.empty()){
		int now[] = {MyQueue.front().first,MyQueue.front().second};
		MyQueue.pop();

		for(int i=0;i<6;i++){
			int x = dx[i]+now[0];
			int y = dy[i]+now[1]+dz[i]*H;
			if(x>=0&&y>=0&&x<M&&y<N){
				if(A[y][x]==0){
					MyQueue.push(make_pair(x,y));
					A[y][x]= A[now[1]][now[0]]+1;
					totalCount--;
				}
			}
		}
	}
}