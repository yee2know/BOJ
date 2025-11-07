#include <vector>
#include <iostream>
using namespace std;

void solve(){
	string s;
	cin >> s;
	vector<int> A;
	string S;
	if(s.size()%3==1) {
		S= "00"+s;
	}else if(s.size()%3==2){
		S = "0"+s;
	}else S=s;
	for(int i=0;i<S.size();i+=3){
		int idx = S.size()-1-i;
		int bit = 1;
		int sum=0;
		for(int j=0;j<3;j++){
			if(S[idx-j]=='1') sum+=bit;
			bit <<=1;
		}
		A.push_back(sum);
	}
	for(int i=A.size()-1;i>=0;i--) cout << A[i];
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}