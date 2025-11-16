//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll paper(int x){
	if(x==136) return 1000;
	else if(x==142) return 5000;
	else if(x==148) return 10000;
	return 50000;
}

void solve(){
 	int N;
	cin >> N;
	ll sum = 0;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		sum += paper(a);
	}
	cout<< sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}