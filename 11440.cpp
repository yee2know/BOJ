//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
#define MOD 1000000007
typedef vector<vector<ll>> mtx;

mtx op(mtx A,mtx B){
	int N = A.size();
	mtx C(N,vector<ll>(N,0));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
			C[i][j]%=MOD;
		}
	}
	return C;
}

ll fibo(ll N){
	mtx ans = {{1,0},{0,1}};
	mtx A = {{1,1},{1,0}};
	while(N>0){
		if(N%2==1){
			ans = op(ans,A);
		}
		A = op(A,A);
		N/=2;
	}
	return ans[0][1];
}


void solve(){
	ll N;
	cin >> N;
	ll a1 = fibo(N)%MOD;
	ll a2 = fibo(N+1)%MOD;
	ll ans = (a1*a2)%MOD;
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}