#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	while(N--){
		vector<int> A(10);
		for(int i=0;i<10;i++){
			cin >> A[i];
		}
		sort(A.begin(),A.end());
		cout << A[7] << "\n";
	}
	return 0;
}