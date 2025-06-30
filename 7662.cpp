#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	multiset<int> pq;
	while(T--){
		pq.clear();
		int K;
		cin >> K;
		while(K--){
			char op;
			int num;
			cin >> op >> num;
			if(op=='I'){
				pq.insert(num);
			}else if(op=='D'){
				if(!pq.empty()){
					if(num==-1){
						pq.erase(pq.begin());
					}else if(num==1){
						pq.erase(--pq.end());
					}
				}
			}
		}
		if(pq.empty()) cout << "EMPTY\n";
		else {
			cout << *pq.rbegin() << " " << *pq.begin() << "\n";
		}
	}
	return 0;
}