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
	int l=1;
	while(N--){
		int x;
		cin >> x;
		vector<int> A(x);
		for(int i=0;i<x;i++) cin >> A[i];
		sort(A.begin(),A.end());
		int gap=0;
		for(int i=0;i<x-1;i++){
			if(abs(A[i]-A[i+1])>gap) gap=abs(A[i]-A[i+1]);
		}
		cout << "Class "<< l<< "\n";
		cout << "Max " << A[x-1] << ", Min " << A[0] << ", Largest gap "<<gap<<"\n";
		l++;
	}
	return 0;
}