//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	int N,M;
	cin >> N >> M;
	ll sum=0;
	for(int i=0;i<N;i++){
		int a;
		cin >> a;
		sum+=a;
	}
	for(int i=0;i<M;i++){
		int a;
		cin >> a;
		if(a==0) continue;
		sum*=a;
	}
	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}