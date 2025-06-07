#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<string>> A(51);
vector<int> valid(51,0);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string temp;
	int N;
	cin >>N;
	for(int i=0;i<N;i++){
		string temp;
		cin >> temp;
		A[temp.size()].push_back(temp);
		valid[temp.size()]=1;
	}
	for(int i=1;i<51;i++){
		if(valid[i])
		sort(A[i].begin(),A[i].end());
	}
	for(int i=1;i<51;i++){
		if(valid[i]==0) continue;
		for(int j=0;j<A[i].size();j++){
			if(temp==A[i][j]) continue;
			temp = A[i][j];
			cout << temp << "\n";
		}
	}
	return 0;
}