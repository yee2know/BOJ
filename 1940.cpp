#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,m,max=0,counter=0;
	cin >> n;
	cin >> m;
	vector<int> A(n,0);
	for(int i=0;i<n;i++){
		cin >> A[i];
		if(max<A[i]) max=A[i];
	}
	vector<int> B(10000001,0);
	for(int i=0;i<n;i++){
		B[A[i]]++;
	}
	for(int i=0;i<n;i++){
		if(m-A[i]<0) continue;
		if(m-A[i]==A[i]) continue;
		if(B[m-A[i]]==1){
			counter++;
			B[m-A[i]]=0;
			B[A[i]]=0;
		}
	}
	cout << counter;
	return 0;
}