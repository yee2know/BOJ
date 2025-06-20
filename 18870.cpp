#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	vector<int> A(N);
	vector<int> B(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	B=A;
	sort(A.begin(),A.end());
	for(int i=1;i<N;i++){

	}
	return 0;
}