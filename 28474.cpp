//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

void solve(){
	ll N;
	cin >> N;
	if(N==1){
		cout << 0 << '\n';
		return;
	}
	if(N==2){
		cout << 1 << '\n';
		return;
	}
	ll M = N;
	ll cnt = N;
	for(ll p =2;p<=sqrt(N);p++){
		if(N%p==0){
			cnt -= (cnt/p);

			while(N%p==0) N/=p;
		}
	}
	if(N>1) cnt-=cnt/N;
	//gcd = 1인 개수

	if(M%2==0){
	M/=2;
	ll cnt2=M;
	for(ll p =2;p<=sqrt(M);p++){
		if(M%p==0){
			cnt2 -= (cnt2/p);

			while(M%p==0) M/=p;
		}
	}
	if(M>1) cnt2-=cnt2/M;
	//gcd = 2인 경우도 세야함 이건 ㅅㅂ 어케함ㄱ
	cnt+=cnt2;
	}
	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--)
    solve();
	return 0;
}