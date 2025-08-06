#include <vector>
#include <iostream>
using namespace std;
typedef pair<int,int> co;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<co> A(N+1);
	for(int i=1;i<=N;i++){
		int t,p;
		cin >> t >> p;
		A[i] = {t,p};
	}
	vector<int> D(N+2,0);
	D[0]=D[1]=0;
	for(int i=1;i<=N;i++){
		if(D[i+1]<D[i]) D[i+1]=D[i];
		if(i+A[i].first<=N+1&&A[i].second+D[i]>D[i+A[i].first]){
			D[i+A[i].first] = A[i].second+D[i];
		}
	}
	cout << D[N+1];
	return 0;
}