#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,c;
	cin >> a >> b >> c;
	int minnum = min(a,min(b,c));
	vector<int> A(a);
	vector<int> B(b);
	vector<int> C(c);
	for(int i=0;i<a;i++) cin >> A[i];
	for(int i=0;i<b;i++) cin >> B[i];
	for(int i=0;i<c;i++) cin >> C[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	int sum=0;
	for(int i=0;i<a;i++) sum+=A[i];
	for(int i=0;i<b;i++) sum+=B[i];
	for(int i=0;i<c;i++) sum+=C[i];
	cout << sum<< "\n";
	for(int i=0;i<minnum;i++){
		A[A.size()-1-i]*=0.9;
		B[B.size()-1-i]*=0.9;
		C[C.size()-1-i]*=0.9;
	}
	sum=0;
	for(int i=0;i<a;i++) sum+=A[i];
	for(int i=0;i<b;i++) sum+=B[i];
	for(int i=0;i<c;i++) sum+=C[i];
	cout << sum;
	return 0;
}