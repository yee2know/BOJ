#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N,M;
	cin >> N >> M;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	int count =0;
	int sum=0;
	int l=0,r=0;
	while(true){
		if(sum>=M){
			if(sum==M) count++;
			sum-=A[l++];
		}else{
			if(r==N) break;
			sum+=A[r++];
		}
	}
	cout << count;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}