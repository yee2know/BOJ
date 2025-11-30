//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll unsigned long long
using namespace std;
#define MOD 9901

ll pow_mod(ll exp) {
    ll res = 1;
	ll base = 2;
    while (exp>0) {
        if(exp%2==1) res=(res*base)%MOD;
        base = (base*base)%MOD;
        exp /=2;
    }
    return res;
}

ll T(ll N,ll R){
	if(R==3){
		return ((pow_mod(N))-1)%MOD;
	}
	if(N==1) return 1;
	ll K = N-round(sqrt(2*N+1))+1;
	return (2*T(K,R)+T(N-K,R-1))%MOD;
}

void solve(){
	ll Case = 1;
	ll N;
	cin >> N;
	cout << T(N,4);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}