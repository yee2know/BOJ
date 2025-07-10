#include <vector>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int min,max;
  cin >> min >> max;
  vector<long long> A(max-min+1);
  //A[0]=min
  for(int i=0;i<max-min+1;i++){
    A[i]=i+min;
  }
  
  return 0;
}