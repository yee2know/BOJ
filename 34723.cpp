//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	int P,M,C,X;
	cin >> P >> M >> C >> X;
	int Min = 2000000000;
	for(int i=1;i<=P;i++){
		for(int j=1;j<=M;j++){
			for(int k=1;k<=C;k++){
				Min = min(Min,abs((i+j)*(j+k)-X));
			}
		}
	}
	cout << Min;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}