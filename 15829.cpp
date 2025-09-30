#include <vector>
#include <iostream>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int L;
	cin >> L;
	string S;
	cin >> S;
	ll M = 1234567891;
	ll result = 0;
	ll r=1;
	for(int i=0;i<L;i++){
		ll now = S[i] - 'a'+1;
		now*=r%M;
		result+=now%M;
		result%=M;
		r*=31;
		r%=M;
	}
	cout << result%M;
	return 0;
}