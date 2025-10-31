#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> jewel;
void solve(){
	int N,K;
	cin >> N >> K;
	vector<jewel> A(N);
	vector<int> B(K);
	priority_queue<int> pq;
	for(int i=0;i<N;i++){
		cin >> A[i].first >> A[i].second;
	}
	for(int i=0;i<K;i++){
		cin >> B[i];
	}
	long long result=0;
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int idx=0;
	for(int i=0;i<K;i++){
		while(idx<N&&A[idx].first<=B[i]){
			pq.push(A[idx].second);
			idx++;
		}
		if(!pq.empty()){
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}