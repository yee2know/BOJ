#include <vector>
#include <iostream>
using namespace std;
static char A[501][501];
void solve(){
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> A[i][j];
		}
	}
	//1 6
	//2 5
	//3 4
	for(int j=1;j<=M;j++){
		for(int i=1;i<=N;i++){
			if(A[i][j]!='.')
				A[i][M-j+1] = A[i][j];
			if(A[i][M-j+1]!='.')
				A[i][j] = A[i][M-j+1];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout << A[i][j];
		} cout << '\n';
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