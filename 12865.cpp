#include <vector>
#include <iostream>
using namespace std;
typedef pair<int,int> item;
void solve(){
	int N,K;
	cin >> N >> K;
	vector<item> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i].first >> A[i].second;
	}
	vector<int> D(K+1,0);
	for(int i=0;i<N;i++){
		int w = A[i].first;
		int v = A[i].second;

		for(int j = K;j>=w;j--){
			D[j] = max(D[j],D[j-w]+v);
		}
	}
	int maxV=0;
	for(int i=0;i<=K;i++) maxV = max(maxV,D[i]);
	cout << maxV;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}