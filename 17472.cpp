#include <vector>
#include <queue>
#include <iostream>
using namespace std;
static vector<int> parent;
static vector<pair<int,int>> lists;
static int dx[] = {0,-1,0,1};
static int dy[] = {1,0,-1,0};
static int map[101][101];
static bool visited[101][101] = {false};
static int N,M,sNum;
static vector<vector<pair<int,int>>> sumlist;
typedef struct Edge {
	int s,e,v;
	bool operator > (const Edge& temp) const{
		return v > temp.v;
	}
} Edge;
static priority_queue<Edge , vector<Edge>, greater<Edge>> pq;
int find(int a){
	if(a==parent[a]) return a;
	else{
		return parent[a]=find(parent[a]);
	}
}
void Union(int a,int b){
	a=find(a);
	b=find(b);

	if(a!=b){
		parent[b]=a;
	}
}
void BFS(int i,int j){
	queue<pair<int,int>> q;
	lists.clear();
	q.push({i,j});
	lists.push_back({i,j});
	visited[i][j]=true;
	map[i][j]=sNum;

	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for(int d=0;d<4;d++){
			int tempR = dx[d];
			int tempC = dy[d];

			while(r+tempR>=0&&r+tempR<N&&c+tempC>=0&&c+tempC<M){
				if(!visited[r+tempR][c+tempC]&&map[r+tempR][c+tempC]!=0){
					int now_i = r+tempR;
					int now_j = c+tempC;
					map[now_i][now_j]=sNum;
					visited[now_i][now_j]=true;
					lists.push_back({now_i,now_j});
					q.push({now_i,now_j});
				}else break;
				if(tempR<0) tempR--;
				else if(tempR>0) tempR++;
				else if(tempC<0) tempC--;
				else if(tempC>0) tempC++;
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
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
		}
	}
	sNum=1;
		for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]!=0&&!visited[i][j]){
			BFS(i,j);
			sNum++;
			sumlist.push_back(lists);
		}}
	}
	for(int i=0;i<sumlist.size();i++){
		vector<pair<int,int>> now = sumlist[i];

		for(int j=0;j<now.size();j++){
			int r = now[j].first;
			int c = now[j].second;
			int nowS = map[r][c];

			for(int d =0; d<4;d++){
				int R = dx[d];
				int C = dy[d];
				int blength = 0;
				while(R+r>=0&&R+r<N&&C+c>=0&&C+c<M){
					if(map[r+R][c+C]==nowS) break;
					else if(map[r+R][c+C]!=0){
						if(blength>1) {
							pq.push(Edge{nowS,map[r+R][c+C],blength});
						}
						break;
					}
					else {
						blength++;
					}
					if(R<0)R--;
					else if(R>0)R++;
					else if(C<0)C--;
					else if(C>0)C++;
				}
			}
		}
	}
	parent.resize(sNum);
	for(int i=0;i<parent.size();i++) parent[i]=i;
	int uE=0;
	int result=0;

	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();

		if(find(now.s)!=find(now.e)){
			Union(now.s,now.e);
			result = result + now.v;
			uE++;
		}
	}
	if(uE==sNum-2) cout << result;
	else cout << -1;
	return 0;
}