#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int temp_age;
	string temp_name;
	cin >> N;
	vector<int> index;
	vector<vector<string>> A(201);
	for(int i=0;i<N;i++){ //입력
		cin >> temp_age >> temp_name;
		A[temp_age].push_back(temp_name);
		index.push_back(temp_age);
	}
	sort(index.begin(),index.end());
	index.erase(unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++){
		for(int j=0;j<A[index[i]].size();j++){
			cout << index[i] << " " << A[index[i]][j] << "\n";
		}
	}
	
	return 0;
}