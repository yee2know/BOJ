#include <vector>
#include <iostream>
#include <queue>
#define INF 3000001
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int V,E,start;
	cin >> V >> E >> start;
	vector<vector<pair<int,int>>> A(V+1);
	for(int i=0;i<E;i++){
		int u,v,w;
		cin >> u >> v >> w;
		A[u].push_back(make_pair(v,w));
	}
	vector<int> D(V+1,INF);
	D[start]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	vector<int> visited(V+1,false);
	q.push(make_pair(0,start));

	while(!q.empty()){
		pair<int,int> now = q.top();
		q.pop();
		if(visited[now.second]) continue;
		visited[now.second]=true;

		for(int i=0;i<A[now.second].size();i++){
			pair<int,int> tmp = A[now.second][i];
			if(D[tmp.first]>D[now.second]+tmp.second){
				D[tmp.first]=D[now.second]+tmp.second;
				q.push(make_pair(D[tmp.second],tmp.first));
			}
		}
	}
	for(int i=1;i<=V;i++){
		if(!visited[i])
			cout << "INF\n";
		else
			cout << D[i] << "\n";
	}
	return 0;
}