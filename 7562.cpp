#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
static int dx[] = {-2,-1,1,2,2,1,-1,-2};
static int dy[] = {1,2,2,1,-1,-2,-2,-1};


typedef pair<int,int> cd;
typedef tuple<int,int,int> coord;
void solve(){
	int I;
	cd from;
	cd to;
	cin >> I;
	cin >> from.first >> from.second;
	cin >> to.first >> to.second;
	if(from==to){
		cout << 0 << "\n";
		return;
	}
	vector<vector<bool>> visited(I,vector<bool>(I,false));
	queue<coord> q;
	q.push({0,from.first,from.second});
	while(!q.empty()){
		coord now = q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int x = get<1>(now)+dx[i];
			int y = get<2>(now)+dy[i];
			if(x>=0&&y>=0&&x<I&&y<I){
				if(!visited[x][y]){
					if(x==to.first&&y==to.second){
						cout << get<0>(now)+1 << "\n";
						return;
					}
					visited[x][y]=true;
					q.push({get<0>(now)+1,x,y});
				}
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--) solve();
	return 0;
}