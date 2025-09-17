#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	typedef tuple<int,int,char> key;
	priority_queue<key,vector<key>,greater<key>> pq;
	for(int i=0;i<M;i++){
		int a,b;
		char c;
		cin >> a >> b >> c;
		pq.push({b,a,c});
	}
	for(int i=0;i<M;i++){
		key now = pq.top();
		pq.pop();
		cout << get<2>(now);
	}
	return 0;
}