#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long D,P,Q;
	cin >> D >> P >> Q;
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	if(P>Q) {
		long long tmp=P;
		P=Q;
		Q=tmp;
	}
	pq.push(P);
	pq.push(Q);
	while(1){
		long long now = pq.top();
		pq.pop();
		if(now>=D){
			cout << now;
			return 0;
		}else{
			pq.push(now+P);
			pq.push(now+Q);
		}
	}
	return 0;
}