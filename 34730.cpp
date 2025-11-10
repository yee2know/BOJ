//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
typedef tuple<ll,ll,ll> node; //시간,도착노드,활성주기
typedef pair<ll,ll> Q; //시간 현재노드

void solve(){
	ll N,M,K,S,T;
	cin >> N >> M >> K >> S >> T;
	vector<vector<bool>> visited(N+1,vector<bool>(K,false)); // [현재 노드][나머지 0인 수]
	vector<vector<node>> A(N+1);
	for(ll i=0;i<M;i++){
		ll a,b,c,d;
		cin >> a >> b >> c>> d;
		A[a].push_back({c,b,d});
	}

	priority_queue<Q,vector<Q>,greater<Q>> pq;
	pq.push({0,S});
	while(!pq.empty()){
		Q now = pq.top();
		pq.pop();
		ll time = now.first;
		ll nownode = now.second;
		if(visited[nownode][time%K]) continue;
		visited[nownode][time%K] = true;
		if(nownode==T){
			cout << time;
			return;
		}
		for(node i : A[nownode]){
			if(time%get<2>(i)==0){
				pq.push({time+get<0>(i),get<1>(i)});
			}
		}
	}
	cout << -1;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}