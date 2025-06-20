#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	unordered_map<string,int> A;
	vector<string> B;
	string temp;
	for(int i=0;i<N;i++){
		cin >> temp;
		A[temp]=1;
	}
	for(int i=0;i<M;i++){
		cin >> temp;
		if(A.find(temp)!=A.end()){
			B.push_back(temp);
		}
	}
	sort(B.begin(),B.end());
	cout << B.size() << "\n";
	for(int i=0;i<B.size();i++) cout << B[i] << "\n";
	return 0;
}