//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;
typedef pair<ll,string> driver;
void solve(){
	ll N,T;
	cin >> N >> T;
	vector<driver> A(N);
	for(ll i=0;i<N;i++){
		string s; ll d;
		cin >> s >> d;
		A[i] = {d,s};
	}
	vector<driver> D(N);
	D[0] = {A[0].first,A[0].second};
	for(ll i=1;i<N;i++){
		D[i] = {D[i-1].first+A[i].first,A[i].second};
	}
	for(ll i=0;i<N;i++){
		D[i].first %= T;
	}
	sort(D.begin(),D.end());
	vector<string> DRS;
	for(ll i=1;i<N;i++){
		if(D[i].first-D[i-1].first<=1000) DRS.push_back(D[i].second);
	}
	if(T-D[N-1].first<=1000) DRS.push_back(D[0].second);
	if(DRS.empty()){
		cout << -1;
		return;
	}
	sort(DRS.begin(),DRS.end());
	for(ll i=0;i<DRS.size();i++){
		cout << DRS[i] << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}