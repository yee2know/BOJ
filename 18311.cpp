#include <vector>
#include <iostream>
using namespace std;

void solve(){
	long long N,K;
	cin >> N >> K;
	vector<long long> A(N);
	for(long long i=0;i<N;i++){
		cin >> A[i];
	}
	vector<long long> B(N*2);
	B[0]=A[0];
	for(long long i=1;i<N;i++){
		B[i]= A[i]+B[i-1];
	}
	for(long long i=N;i<N*2;i++){
		B[i]= A[2*N-i-1]+B[i-1];
	}
	for(long long i=0;i<N;i++){
		if(K<B[i]) {
			cout << i+1;
			return;
		}
	}
	for(long long i=N;i<N*2;i++){
		if(K<B[i]) {
			cout << 2*N-i;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}