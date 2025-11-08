#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N,M;
	cin >> N >> M;
	vector<int> C(N+M);
	int l1=0,l2=0;
	vector<int> A(N+1);
	vector<int> B(M+1);
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<M;i++) cin >> B[i];
	A[N] = B[M] = 1500000000;
	int idx=0;
	while(l1<N||l2<M){
		if(A[l1]>B[l2]){
			C[idx++] = B[l2];
			l2++;
		}else{
			C[idx++] = A[l1];
			l1++;
		}
	}
	for(int i=0;i<N+M;i++) cout << C[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();	
	return 0;
}