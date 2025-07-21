#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int N;
		cin >> N;
		int A[2][N];
		for(int i=0;i<2;i++){
			for(int j=0;j<N;j++){
				cin >> A[i][j];
			}
		}
		vector<vector<int>> D(2, vector<int>(N, 0));
		D[0][0]=A[0][0];
		D[1][0]=A[1][0];
		D[0][1]=A[0][1]+A[1][0];
		D[1][1]=A[1][1]+A[0][0];
		for(int i=2;i<N;i++){
			D[0][i]= max(D[1][i-1],D[1][i-2])+A[0][i];
			D[1][i]= max(D[0][i-1],D[0][i-2])+A[1][i];
		}
		cout << max(D[0][N-1],D[1][N-1]) << "\n";
	}
	return 0;
}