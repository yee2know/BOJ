#include <vector>
#include <queue>
#include <iostream>
#define INF 2100000000
using namespace std;
typedef pair<int, int> edge;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	vector<int> dist(N+1,INF);
	vector<bool> visited(N+1,false);
	vector<vector<edge>> A(N+1);
	for(int i=0;i<M;i++){
		int s,e,w;
		cin >> s >> e >> w;
		A[s].push_back(make_pair(e,w));
	}
	int start,end;
	cin >> start >> end;
	priority_queue<edge,vector<edge>,greater<edge>> pq;
	pq.push(make_pair(0,start));
	dist[start]=0;

	while(!pq.empty()){
		edge now = pq.top();
		pq.pop();
		if(!visited[now.second]){
			visited[now.second]=true;
			for(edge i : A[now.second]){
				if(dist[i.first]>dist[now.second]+i.second){
					dist[i.first]=dist[now.second]+i.second;
					pq.push(make_pair(dist[i.first],i.first));
				}
			}
		}
	}
	cout << dist[end];
	return 0;
}