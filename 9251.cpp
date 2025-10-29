#include <vector>
#include <iostream>
using namespace std;

void solve(){
	string A,B;
	cin >> A >> B;
	vector<vector<int>> D(A.size()+1,vector<int>(B.size()+1));
	//LCS 구현
	for(int i=0;i<=A.size();i++){
		for(int j=0;j<=B.size();j++){
			if(i==0||j==0) D[i][j]=0;
			else if(A[i-1]==B[j-1]) D[i][j] = D[i-1][j-1]+1;
			else{
				D[i][j]= max(D[i-1][j],D[i][j-1]);
			}
		}
	}
	int maxV=0;
	for(int i=0;i<=A.size();i++){
		for(int j=0;j<=B.size();j++){
			maxV = max(maxV,D[i][j]);
		}
	}
	cout << maxV;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}