#include <cmath>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long result = n;

  for(long long p=2;p<=sqrt(n);p++){
	if(n%p==0){
		result = result - result/p;

		while(n%p==0) n/=p;
	}
  }
  if(n>1) result-=result/n;
  cout << result;
  return 0;
}