//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	int cnt = 0;
	for(int i=0;i<N;i++){

		for(int j=i;j>=0;j--){
			if(A[i]<A[j]) cnt++;
		}
	}
	if(cnt%2==0) cout << "Yes";
	else cout << "No";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}