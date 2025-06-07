#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> A(n,0);
	for(int i=0;i<n;i++) cin >> A[i];
	sort(A.begin(),A.end());
	for(int i=0;i<n;i++){
		cout << A[i] << "\n";
	}
	return 0;
}