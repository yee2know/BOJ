//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define ll long long
using namespace std;
static vector<int> parent;
static int N,M;
typedef tuple<int,int,int> node;
int Find(int a){
	if(a==parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a,int b){
	a = Find(a);
	b = Find(b);

	if(a!=b) parent[b] = a;
}

void solve(){
	parent.resize(N+1);
	ll allSum = 0;
	priority_queue<node,vector<node>,greater<node>> pq;
	for(int i=0;i<=N;i++) parent[i]=i;
	for(int i=0;i<M;i++){
		int x,y,z;
		cin >> x >> y >> z;
		allSum+=z;
		pq.push({z,x,y});
	}
	ll sum = 0;
	int cnt = 0;
	while(!pq.empty()){
		node now = pq.top();
		pq.pop();
		int a = Find(get<1>(now));
		int b = Find(get<2>(now));
		int p = get<0>(now);
		if(a!=b){
			Union(a,b);
			sum+=p;
			cnt++;
			if(cnt==N-1){
				cout << allSum - sum << "\n";
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true){
	cin >> N >> M;
	if(N==0&&M==0) return 0;
    solve();
	}
	return 0;
}