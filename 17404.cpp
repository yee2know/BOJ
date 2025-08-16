#include <vector>
#include <iostream>
using namespace std;
#define MAX 100000000
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int A[1001][3];
	for(int i=1;i<=N;i++){
		for(int j=0;j<3;j++){
			cin >> A[i][j];
		}
	}
	int D[1001][3];
	int result = MAX+1000000;
	for(int p=0;p<3;p++){
		//p : 처음에 고를 수
		for(int i=0;i<3;i++){
			D[1][i] = (i==p)?A[1][i]:MAX;
		}
		for(int i=2;i<=N;i++){
			for(int j=0;j<3;j++){
				D[i][j]=min(D[i-1][(j+1)%3],D[i-1][(j+2)%3])+A[i][j];
			}
		}
		for(int i=0;i<3;i++){
			if(i==p) continue;
			result = min(result,D[N][i]);
		}
	}
	cout << result;
	return 0;
}