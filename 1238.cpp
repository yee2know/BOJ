#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> edge;
#define INF 210000000
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M,X;
	cin >> N >> M >> X;
	vector<vector<edge>> A(N+1);
	vector<vector<edge>> rA(N+1);
	for(int i=0;i<M;i++){
		int s,e,v;
		cin >> s >> e >> v;
		A[e].push_back(make_pair(s,v));
		rA[s].push_back(make_pair(e,v));
	}
	vector<int> D(N+1,INF);
	vector<int> rD(N+1,INF);
	D[X]=0;
	rD[X]=0;
	priority_queue<edge, vector<edge>, greater<edge>> B;
	B.push(make_pair(0,X));
	while(!B.empty()){
		int dist = B.top().first;
		int cur = B.top().second;
		B.pop();

		for(edge i : A[cur]){
			if(D[i.first]>i.second+D[cur]){
				D[i.first]=i.second+D[cur];
				B.push(make_pair(D[i.first],i.first));
		}}
	}
	B.push(make_pair(0,X));
	while(!B.empty()){
		int dist = B.top().first;
		int cur = B.top().second;
		B.pop();

		for(edge i : rA[cur]){
			if(rD[i.first]>i.second+rD[cur]){
				rD[i.first]=i.second+rD[cur];
				B.push(make_pair(rD[i.first],i.first));
		}}
	}
	int max=0;
	for(int i=1;i<=N;i++){
		if(max<D[i]+rD[i]) max = D[i]+rD[i];
	}
	cout << max;
	return 0;
}