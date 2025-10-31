#include <vector>
#include <iostream>
#include <queue>
using namespace std;
static int N,M;
static int dx[] = {-1,0,1,0};
static int dy[] = {0,1,0,-1};
static int flag;
typedef pair<int,int> node;
static vector<vector<char>> A;
static vector<vector<pair<int,int>>> B;
static vector<vector<bool>> visited;
void check(int x,int y){
	if(A[x][y]=='1') return;
	queue<node> q;
	q.push({x,y});
	visited[x][y]=true;
	int result = 1;
	vector<node> C;
	C.push_back({x,y});	
	while(!q.empty()){
		node now = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int X = now.first + dx[i];
			int Y = now.second + dy[i];
			if(X>=0&&Y>=0&&X<N&&Y<M&&A[X][Y]=='0'&&!visited[X][Y]){
				visited[X][Y] = true;
				q.push({X,Y});
				result++;
				C.push_back({X,Y});	
			}
		}
	}
	for(int i=0;i<C.size();i++){
		B[C[i].first][C[i].second]={result,flag};
	}
	flag++;
	return;
}

void solve(){
	cin >> N >> M;
	flag=0;
	A.resize(N);
	for(int i=0;i<N;i++){
		A[i].resize(M);
	}
	visited.assign(N,vector<bool>(M,false));
	B.assign(N,vector<pair<int,int>>(M,{0,-1}));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(A[i][j]=='0'&&!visited[i][j])
			check(i,j);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(A[i][j]=='0') cout << 0;
			else{
				int result = 1;
				vector<int> dup;
				for(int k=0;k<4;k++){
					int X = i + dx[k];
					int Y = j + dy[k];
					if(X>=0&&Y>=0&&X<N&&Y<M&&A[X][Y]=='0'){
						int dup1 = B[X][Y].second;
						bool isDup=false;
						for(int i : dup){
							if(i==dup1) isDup=true;
						}
						if(!isDup){
						result+=B[X][Y].first;
						dup.push_back(dup1);
						}
					}
				}cout << result%10;
			}
		}cout << '\n';
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