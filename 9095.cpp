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
  int D[20];
  D[1]=1; //1
  D[2]=2; //11 2
  D[3]=4; //111 12 21 3
  for(int i=4;i<=11;i++){
	D[i]=D[i-1]+D[i-2]+D[i-3];
  }
  while(t--){
	int n;
	cin >> n;
	cout << D[n] << "\n";
  }
  return 0;
}