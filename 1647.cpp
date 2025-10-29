#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

static vector<int> parent;
int Find(int a){
	if(parent[a]==a) return a;
	else return parent[a]=Find(parent[a]);
}

void Union(int a,int b){
	a = Find(a);
	b = Find(b);
	if(a!=b) parent[a]=b;
}

void solve(){
	int N,M;
	cin >> N >> M;
	typedef tuple<int,int,int> node;
	priority_queue<node,vector<node>,greater<node>> pq; //작은게 먼저
	parent.resize(N+1);
	for(int i=0;i<=N;i++) parent[i]=i;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		pq.push({c,a,b});
	}
	int nodes=0;
	int value=0;
	while(!pq.empty()){
		node now = pq.top();
		pq.pop();
		if(Find(get<1>(now))!=Find(get<2>(now))){
			//순환 없으면
			nodes++;
			value+=get<0>(now);
			if(nodes==N-1) {
				value-=get<0>(now);
				break;
			}
			Union(get<1>(now),get<2>(now));
		}
	}
	cout << value;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}