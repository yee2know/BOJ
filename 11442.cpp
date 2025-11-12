//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
#define MOD 1000000007
typedef vector<vector<ll>> matrix;

matrix Multi(matrix A,matrix B){
	int N = A.size();
	matrix C(N,vector<ll>(N,0));
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
	if(N<=1) return N;
	matrix ans = {{1,0},{0,1}};
	matrix A = {{1,1},{1,0}};
	while(N>0){
		if(N%2==1){
			ans = Multi(ans,A);
		}
		A = Multi(A,A);
		N/=2;
	}
	return ans[0][1];
}


void solve(){
	ll a;
	cin >> a;
	if(a%2==1) a+=1;
	cout << fibo(a);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}