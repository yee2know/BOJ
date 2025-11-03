#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N;
	cin >> N;
	int M;
	cin >> M;
	int sum=0;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		sum += a*b;
	}
	if(sum==N) cout << "Yes";
	else cout << "No";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}