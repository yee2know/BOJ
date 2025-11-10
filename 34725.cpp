//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static int A[1001][1001];
static int N,M;
void fillK(int x,int y,int k){
	int x2,y2;
	for(int i = x;i<N;i++){
		if(A[i][y]==0) x2=i;
		else break;
	}
	for(int i = y;i<M;i++){
		if(A[x][i]==0) y2=i;
		else break;
	}
	A[x][y] = k; A[x2][y] =  k; A[x][y2] = k; A[x2][y2] = k;
}

void solve(){
	cin >> N >> M;
	int K=1;
	for(int i=0;i<N/2;i++){
		for(int j=0;j<M/2;j++){
			fillK(i,j,K);
			K++;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << A[i][j] << ' ';
		}
		cout << '\n';
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