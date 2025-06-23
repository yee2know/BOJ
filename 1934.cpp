#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int a,int b){
	int result=0;
	int A = max(a,b);
	int B = min(a,b);
	while(1){
		result = A%B;
		if(result==0) return B;
		A=B;
		B=result;
	}
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
	int a,b;
	cin >> a >> b;
	cout << a*b/gcd(a,b) << "\n";
  }
  return 0;
}