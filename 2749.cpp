/*
주기의 길이가 P 이면, N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같습니다.

M = 10k 일 때, k > 2 라면, 주기는 항상 15 × 10k-1 입니다. 이 사실을 모른다고 해도, 주기를 구하는 코드를 이용해서 문제를 풀 수 있습니다.
*/

//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	ll N;
	cin >> N;
	ll cycle = 15*1e5;
	ll M = 1e6;
	vector<ll> A(cycle);
	A[0]=0; A[1]=1;
	for(ll i=2;i<cycle;i++){
		A[i]= (A[i-1] + A[i-2])%M;
	}
	cout << A[N%cycle];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}