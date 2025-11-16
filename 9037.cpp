//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
bool isSame(vector<int> A){
	if(A.size()==1) return true;
	int a= A[0];
	for(int i=0;i<A.size();i++){
		if(a!=A[i]) return false;
	}
	return true;
}
void makeEven(vector<int> &A){
	for(int i=0;i<A.size();i++){
		if(A[i]%2==1) A[i]++;
	}
}
void cycle(vector<int> &A){
	vector<int> B(A.size(),0);
	for(int i=0;i<A.size()-1;i++){
		B[i+1] = A[i]/2;
		A[i]/=2;
	}
	B[0] = A[A.size()-1]/2;
	A[A.size()-1]/=2;
	for(int i=0;i<A.size();i++){
		A[i]+=B[i];
	}
}

void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	int cnt=0;
	makeEven(A);
	if(isSame(A)){
		cout << 0 << '\n';
		return;
	}
	
	while(1){
		cnt++;
		cycle(A);
		makeEven(A);
		if(isSame(A)){
			cout << cnt << '\n';
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--)
    solve();
	return 0;
}