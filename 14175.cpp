#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char A[10][10];
	char B[100][100];
	int N,M,K;
	cin >> M >> N >> K;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >> A[i][j];
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			for(int a=0;a<K;a++){
				for(int b=0;b<K;b++){
					B[i*K+a][j*K+b]=A[i][j];
				}
			}
		}
	}
		for(int i=0;i<M*K;i++){
		for(int j=0;j<N*K;j++){
			cout << B[i][j];
		}
		cout << "\n";
	}
	return 0;
}