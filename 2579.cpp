#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N+1,0);
	for(int i=1;i<=N;i++) cin >> A[i];
	vector<pair<int,int>> D(N+1);
	D[0].first=D[0].second=0;
	D[1].first=A[1];
	D[1].second=0;
	for(int i=2;i<=N;i++){
		if(D[i-1].second==1){
			D[i].first = D[i-2].first + A[i];
			D[i].second=0;
		}else{
			if(D[i-1].first>D[i-2].first){
				D[i].first = D[i-1].first + A[i];
				D[i].second = D[i-1].second+1;
			}else{
				D[i].first = D[i-2].first + A[i];
				D[i].second=0;
			}
		}
		cout << D[i].first << " " << D[i].second << "\n";	}
	cout << D[N].first;
	return 0;
}