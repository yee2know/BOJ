#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
	vector<int> A(N);
	vector<int> B(N);
  for(int i=0;i<N;i++) cin >>A[i];
  for(int i=0;i<N;i++) cin >>B[i];
 sort(A.begin(),A.end()); 
 sort(B.begin(),B.end()); 
 int sum=0;
 for(int i=0;i<N;i++){
	sum+=A[i]*B[N-i-1];
 }
 cout << sum;
  return 0;
}