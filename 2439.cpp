#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		int M = N-i;
		int L = i;
		while(M--) cout << ' ';
		while(L--) cout << '*';
		cout << "\n";
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