#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int,int,int> node;
vector<int> parent;
int Find(int a){
	if(a==parent[a]) return a;
	return parent[a]=Find(parent[a]);
}
void Union(int a,int b){
	a = Find(a);
	b = Find(b);
	if(a!=b) parent[b]=a;
}
void solve(){
	int N,M;
	cin >> N >> M;
	parent.resize(N+1);
	for(int i=0;i<=N;i++) parent[i]=i;
	priority_queue<node,vector<node>,greater<node>> pq;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		pq.push({c,a,b});
	}
	int links = 0;
	int sum = 0;
	while(!pq.empty()){
		node now = pq.top();
		pq.pop();
		int s = get<1>(now);
		int e = get<2>(now);
		int v = get<0>(now);
		if(Find(s)!=Find(e)){
			Union(s,e);
			sum+=v;
			links++;
			if(links==N-1) break;
		}
	}
	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}