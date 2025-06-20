#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum=0,nsum=0,N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		int temp;
		cin >> temp;
		A[i]=temp;
		sum+=temp;
	}
	nsum=sum;
	for(int i=0;i<N;i++){
		int temp;
		cin >> temp;
		if(temp==1) nsum-=A[i];
	}
	cout << sum << "\n";
	cout << nsum;
	return 0;
}