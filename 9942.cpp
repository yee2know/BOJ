//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll unsigned long long
using namespace std;

ll T(ll N,ll R){
	if(R==3){
		return (1ULL<<N)-1;
	}
	if(N==1) return 1;
	ll K = N-round(sqrt(2*N+1))+1;
	return 2*T(K,R)+T(N-K,R-1);
}

void solve(){
	ll Case = 1;
	ll N;
	while(cin >> N){
		cout << "Case " << Case << ": " << T(N,4) <<"\n";
		Case++;
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