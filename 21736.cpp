#include <iostream>
#include <vector>
using namespace std;
static vector<string> A;
static int dx[] = {0,-1,0,1};
static int dy[] = {1,0,-1,0};
static int counter;
static vector<vector<bool>> visited;
void DFS(int x,int y,int N,int M);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	A.resize(N);
	visited = vector<vector<bool>>(N,vector<bool>(M,false));
	string temp;
	for(int i=0;i<N;i++){
		cin >> temp;
		A[i]=temp;
	}
	int Ix,Iy;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(A[i][j]=='I'){
				Ix=i;
				Iy=j;	
			}
		}
	}
	counter=0;
	DFS(Ix,Iy,N,M);
	if(counter==0) cout << "TT";
	else cout << counter;
	return 0;
}

void DFS(int x,int y,int N,int M){
	visited[x][y]=true;
	if(A[x][y]=='P') counter++;
	for(int i=0;i<4;i++){
		int X = x + dx[i];
		int Y = y + dy[i];
		if(X>=0&&Y>=0&&X<N&&Y<M){
			if(A[X][Y]!='X'&&!visited[X][Y]){
				DFS(X,Y,N,M);
			}
		}
	}
}