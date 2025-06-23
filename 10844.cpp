#include <vector>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long D[101][10];
  for(int i=1;i<=9;i++) D[1][i]=1;
  D[1][0]=0;
  for(int i=2;i<=n;i++){
	for(int j=1;j<=8;j++){
		D[i][j]=(D[i-1][j+1]+D[i-1][j-1])%1000000000;
	}
	D[i][9]=D[i-1][8];
	D[i][0]=D[i-1][1];
  }
  long long sum=0;
  for(int i=0;i<=9;i++){
	sum= (sum+D[n][i])%1000000000;
  }
  cout << sum;
  return 0;
}