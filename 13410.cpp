//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int pal(int x){
	int result = 0;
	while(x>0){
		result*=10;
		result+=x%10;
		x/=10;
	}
	return result;
}


void solve(){
	int N,M;
	cin >> N >> M;
	vector<int> A(M);
	int Max=-1;
	for(int i=1;i<=M;i++){
		Max=max(Max,pal(i*N));
	}
	cout << Max;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}