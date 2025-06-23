#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

long long gcd(long long a,long long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a,b;
  cin >> a >> b; 
  long long result= gcd(a,b);
  while(result--){
	cout << 1;
  }
  return 0;
}