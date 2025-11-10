//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	int N;
	cin >> N;
	int cnt= 0;
	while(N--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a>=1000||b>=1600||c>=1500||(d<=30&&d!=-1)) cnt++;
	}
	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}