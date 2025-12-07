//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
static int L,R,C;
static int dx[] = {-1,1,0,0,0,0};
static int dy[] = {0,0,-1,1,0,0};
static int dz[] = {0,0,0,0,-1,1};
typedef tuple<int,int,int> coord;
typedef tuple<int,int,int,int> qcoord;
void solve(){
	char B[30][30][30];
	coord S,E;
	for(int i=0;i<L;i++){
		for(int j=0;j<R;j++){
			for(int k=0;k<C;k++){
				cin >> B[i][j][k];
				if(B[i][j][k]=='S') S = {i,j,k};
				else if(B[i][j][k]=='E') E = {i,j,k};	
			}
		}
	}
	bool visited[30][30][30] = {false};
	queue<qcoord> q;
	q.push({get<0>(S),get<1>(S),get<2>(S),0});
	visited[get<0>(S)][get<1>(S)][get<2>(S)] = true;
	while(!q.empty()){
		qcoord now = q.front();
		q.pop();

		for(int i=0;i<6;i++){
			int x = dx[i] + get<0>(now);
			int y = dy[i] + get<1>(now);
			int z = dz[i] + get<2>(now);

			if(x>=0&&y>=0&&z>=0&&x<L&&y<R&&z<C){
				if(!visited[x][y][z]&&B[x][y][z]!='#'){
					if(x==get<0>(E)&&y==get<1>(E)&&z==get<2>(E)){
						cout << "Escaped in " << get<3>(now)+1 << " minute(s).\n";
						return;
					}
					visited[x][y][z]=true;
					q.push({x,y,z,get<3>(now)+1});
				}
			}
		}
	}
	cout << "Trapped!\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true){	
		cin >> L >> R >> C;
		if(L==R&&R==C&&C==0) return 0;
    	solve();
	}
	return 0;
}