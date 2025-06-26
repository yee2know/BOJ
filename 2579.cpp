#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N+1,0);
	for(int i=1;i<=N;i++) cin >> A[i];
	vector<vector<int>> D(N+1, vector<int>(3, -1));
	D[0][0]=0;
	D[0][1]=0;
	D[1][0]=A[1];
	for(int i=2;i<=N;i++){

			D[i][0] = max(D[i-2][0],D[i-2][1]) + A[i];
			D[i][1] = D[i-1][0] + A[i];

	}
	cout << max(D[N][0],D[N][1]);
	return 0;
}
// 9
// 6 15
// 17 -1
// 19 21
// 21 -1