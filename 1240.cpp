#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> node;
static int N,M;
static vector<vector<node>> tree;
static vector<int> dist;
static vector<bool> visited;
int BFS(int s,int e);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	tree.resize(N+1);
	dist.resize(N+1);
	visited.resize(N+1);

	for(int i=1;i<N;i++){
		int s,e,v;
		cin >> s >> e >> v;
		tree[s].push_back({e,v});
		tree[e].push_back({s,v});
	}
	for(int i=0;i<M;i++){
		int s,e;
		cin >> s >> e;
		cout << BFS(s,e) << "\n";
		fill(dist.begin(),dist.end(),0);
		fill(visited.begin(),visited.end(),false);
	}
	return 0;
}

int BFS(int s,int e){
	queue<int> q;
	q.push(s);
	visited[s]=true;

	while(!q.empty()){
		int now = q.front();
		q.pop();

		for(node next : tree[now]){
			if(!visited[next.first]){
				dist[next.first]=next.second+dist[now]; // 거리 업뎃
				visited[next.first]=true; //방문처리
				q.push(next.first);

				if(e==next.first) return dist[next.first];
			}
		}
	}
}