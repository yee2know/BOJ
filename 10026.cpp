#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static vector<vector<char>> A;
static vector<vector<bool>> visited;
static int counter;
static int dx[] = {0,-1,0,1};
static int dy[] = {1,0,-1,0};
void DFS(int x,int y,char a,int N);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	A = vector<vector<char>>(N,vector<char>(N));
	visited = vector<vector<bool>>(N,vector<bool>(N,false));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> A[i][j];
		}
	}
	counter=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				DFS(i,j,A[i][j],N);
				counter++;
			}
		}
	}
	cout << counter << " ";
	counter=0;
	visited = vector<vector<bool>>(N,vector<bool>(N,false));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]=='R') A[i][j] = 'G';
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				DFS(i,j,A[i][j],N);
				counter++;
			}
		}
	}
	cout << counter;
	return 0;
}

void DFS(int x,int y,char a,int N){
	visited[x][y]=true;
	for(int i=0;i<4;i++){
		int X = x + dx[i];
		int Y = y + dy[i];
		if(X>=0&&Y>=0&&X<N&&Y<N){
			if(!visited[X][Y]&&A[X][Y]==a){
				DFS(X,Y,a,N);
			}
		}
	}
}
