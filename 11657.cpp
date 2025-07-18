#include <vector>
#include <iostream>
#include <tuple>
#include <limits.h>
using namespace std;
typedef tuple<int,int,int> edge;
static vector<edge> edges;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int s,e,w;
		cin >> s >> e >> w;
		edges.push_back(make_tuple(s,e,w));
	}
	vector<long> D(N+1,LONG_MAX);
	D[1]=0;
	for(int i=1;i<N;i++){
		for(int j=0;j<M;j++){
			edge medge = edges[j];
			int start = get<0>(medge);
			int end = get<1>(medge);
			int time = get<2>(medge);

			if(D[start]!=LONG_MAX&&D[end]>D[start]+time){
				D[end]=D[start]+time;
			}
		}
	}
	bool mCycle=false;
	for(int i=0;i<M;i++){
		edge medge = edges[i];
			int start = get<0>(medge);
			int end = get<1>(medge);
			int time = get<2>(medge);
		if(D[start]!=LONG_MAX&&D[end]>D[start]+time) mCycle=true;

	}
	if(!mCycle){
		for(int i=2;i<=N;i++){
			if(D[i]==LONG_MAX)
				cout << -1 << "\n";
			else cout << D[i] << "\n";
		}
	}else cout << -1;
	return 0;
}