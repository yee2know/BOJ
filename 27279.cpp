#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	vector<int> A(N);
	priority_queue<int> pq;
	vector<int> B(M);
	for(int i=0;i<N;i++){
		cin >> A[i];
		pq.push(A[i]);
	}
	for(int i=0;i<M;i++){
		cin >> B[i];
	}
	sort(B.begin(),B.end(),greater<int>());
	
	return 0;
}