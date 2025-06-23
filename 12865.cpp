#include <vector>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,K;
  cin >> N >> K;
  int D[K+1];
	vector<vector<int>> A(K+1);
	int w,v;
	for(int i=0;i<N;i++){
		cin >> w >> v;
		A[w].push_back(v);
	}
	for(int i=1;i<=K;i++){
		
	}
  return 0;
}