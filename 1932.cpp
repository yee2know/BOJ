#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  int A[N][N];
  int D[N][N];
  for(int i=0;i<N;i++){
	for(int j=0;j<i+1;j++){
		cin >> A[i][j];
	}
  }
  D[0][0]=A[0][0];
  for(int i=1;i<N;i++){
	for(int j=0;j<i+1;j++){
		if(j==0) D[i][j]=D[i-1][j]+A[i][j];
		else if(j==i) D[i][j]=D[i-1][j-1]+A[i][j];
		else
			D[i][j]= A[i][j] + max(D[i-1][j],D[i-1][j-1]);
	}
  }
  int maxV=0;
  for(int i=0;i<N;i++){
	if(maxV<D[N-1][i]) maxV=D[N-1][i];
  }
  cout << maxV;
  return 0;
}