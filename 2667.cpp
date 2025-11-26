//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
static int N;
static string A[25];
static vector<vector<bool>> visited;
static vector<int> danji;
static int dx[] = {1,0,-1,0};
static int dy[] = {0,1,0,-1};
typedef pair<int,int> node;

void BFS(int x,int y){
	int cnt = 1;
	queue<node> q;
	q.push({x,y});
	visited[x][y]=true;
	while(!q.empty()){
		node now = q.front();
		q.pop();

		for(int i=0;i<4;i++){
			int X = now.first+dx[i];
			int Y = now.second+dy[i];
			if(X>=0&&Y>=0&&X<N&&Y<N){
				if(!visited[X][Y]&&A[X][Y]=='1'){
					visited[X][Y]=true;
					cnt++;
					q.push({X,Y});
				}
			}
		}
	}
	danji.push_back(cnt);
	return;
}

void solve(){
	cin >> N;
	int d = 0;
	visited = vector<vector<bool>>(N,vector<bool>(N,false));
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]=='1'&&!visited[i][j]){
				//cout << i << " " << j << "\n";
				BFS(i,j);
				d++;
			}
		}
	}
	cout << d << "\n";
	sort(danji.begin(),danji.end());
	for(int i=0;i<danji.size();i++){
		cout << danji[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}