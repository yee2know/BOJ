#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<string> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	vector<int> R;
	vector<int> S;
	vector<int> P;
	int round = A[0].size();
	for(int i=0;i<round;i++){
		R.clear();
		S.clear();
		P.clear();
		for(int j=0;j<N;j++) {
			if(A[i][j]=='R') R.push_back(j);
			else if(A[i][j]=='S') S.push_back(j);
			else P.push_back(j);
		}
		if(R.size()>0&&S.size()>0&&P.size()>0) continue;
		if(R.size()==0){
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--) solve();
	return 0;
}