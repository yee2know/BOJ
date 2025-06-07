#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> M(N);
	for(int i=0;i<N;i++) cin >> M[i];
	sort(M.begin(),M.end());
	vector<int> sum(N+1,0);
	int sumsum=0;
	for(int i=1;i<=N;i++){
		sum[i]=sum[i-1]+M[i-1];
		sumsum+=sum[i];
	}
	cout << sumsum;
	return 0;
}