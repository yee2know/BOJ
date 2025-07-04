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
	int A[N+1][3];
	for(int i=0;i<N;i++){
		int a,b,c;
		cin >> a >> b >> c;
		A[i+1][0]=a;
		A[i+1][1]=b;
		A[i+1][2]=c;
	}
	vector<vector<int>> D(N+1,vector<int>(3,0));
	D[1][0]=A[1][0];
	D[1][1]=A[1][1];
	D[1][2]=A[1][2];
	for(int i=2;i<=N;i++){
		D[i][0]=A[i][0]+min(D[i-1][1],D[i-1][2]);
		D[i][1]=A[i][1]+min(D[i-1][0],D[i-1][2]);
		D[i][2]=A[i][2]+min(D[i-1][1],D[i-1][0]);
	}
	int mincol= min(D[N][0],min(D[N][1],D[N][2]));
	cout << mincol;
	return 0;
}