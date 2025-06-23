#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
	vector<pair<int,int>> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i].second >> A[i].first;
	}
	sort(A.begin(),A.end());
	int E=1000001;
	for(int i=N-1;i>=0;i--){
		if(E>A[i].first){
			E=A[i].first-A[i].second;
		}else{
			E-=A[i].second;
		}
	}
	if(E<0) E=-1;
	cout << E;
  return 0;
}