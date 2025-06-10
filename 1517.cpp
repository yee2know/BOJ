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
	vector<pair<int,int>> A(N);
	vector<pair<int,int>> B(N);
	for(int i=0;i<N;i++){
		cin >> A[i].first;
		A[i].second = i;
		B[i]=A[i];
	}
	sort(A.begin(),A.end());
	int result=0;
	for(int i=0;i<N;i++){
		result+=abs(A[i].second-i);
	}
	cout << result;
	return 0;
}
// 3,0 2,1 1,2
// 1,2 2,1 3,0
// 2   0    2