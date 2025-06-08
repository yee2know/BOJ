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
	vector<int> A;
	while(N>0){
		A.push_back(N%10);
		N/=10;
	}
	sort(A.begin(),A.end());
	for(int i=0;i<A.size();i++){
		cout << A[A.size()-1-i];
	}
	return 0;
}