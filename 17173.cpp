#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	vector<int> A(N+1,0);
	for(int i=0;i<M;i++){
		int temp;
		cin >> temp;
		for(int j=temp;j<=N;j+=temp){
			A[j]=1;
		}
	}
	int result=0;
	for(int i=1;i<=N;i++){
		if(A[i]==1){
			result+=i;
		}
	}
	cout << result;
	return 0;
}