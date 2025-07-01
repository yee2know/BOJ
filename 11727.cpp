#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> D(n+1,0);
	D[1]=1;
	D[2]=3;
	for(int i=3;i<=n;i++){
		D[i]=(D[i-1]+2*D[i-2])%10007;
	}
	cout << D[n];
	return 0;
}