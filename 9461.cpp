#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<long long> D(101,0);
		D[1]=D[2]=D[3]=1;
		D[4]=D[5]=2;
		for(int i=6;i<=100;i++)
			D[i] = D[i-1]+D[i-5];
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << D[n] << "\n";
	}
	return 0;
}