#include <vector>
#include <iostream>
using namespace std;
#define ll long long
void solve(){
	//45번째 피보나치 수 부터 10억 7 이상임
	//1134903170
	ll D[100];
	D[0]=0; D[1]=D[2]=1;
	for(int i=3;i<100;i++){
		D[i] = D[i-1]+D[i-2];
	}
	for(int i=0;i<100;i++){
		cout << D[i] << " ";
		if(D[i]==1134903170) cout << "\n" << i << "\n";
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