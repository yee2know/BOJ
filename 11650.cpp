#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int x,y;
	cin >> N;
	vector<vector<int>> A(200001);
	vector<int> index;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		index.push_back(x+100000);
		A[x+100000].push_back(y);
	}
	sort(index.begin(),index.end());
	index.erase(unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++){
		sort(A[index[i]].begin(),A[index[i]].end());
	}
	for(int i=0;i<index.size();i++){
		for(int j=0;j<A[index[i]].size();j++){
			cout << index[i]-100000 << " " << A[index[i]][j] << "\n";
		}
	}
	return 0;
}