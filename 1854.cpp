#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 2100000000
typedef pair<int,int> edge;
static int N,M,K;
static int W[1001][1001];
static priority_queue<int> dist[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i=0;i<M;i++){
		int S,E,V;
		cin >> S >> E >> V;
		W[S][E]=V;
	}
	priority_queue<edge,vector<edge>,greater<edge>> pq;
	pq.push(make_pair(0,1));
	dist[1].push(0);

	while(!pq.empty()){
		edge now = pq.top();
		pq.pop();

		for(int i =1;i<=N;i++){
			if(W[now.second][i]!=0){
				if(dist[i].size()<K){
					dist[i].push(W[now.second][i]+now.first);
					pq.push(make_pair(W[now.second][i]+now.first,i));
				}else if(dist[i].top()>W[now.second][i]+now.first){
					dist[i].pop();
					dist[i].push(W[now.second][i]+now.first);
					pq.push(make_pair(W[now.second][i]+now.first,i));
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(dist[i].size()==K) cout << dist[i].top() << "\n";
		else cout << "-1\n";
	}
	return 0;
}