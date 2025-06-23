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
  int D[N+1];
  D[1]=1; D[2]=2;
  for(int i=3;i<=N;i++){
	D[i] =(D[i-1]+D[i-2])%10007;
  }
  cout << D[N];
  return 0;
}