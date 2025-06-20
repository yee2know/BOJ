#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	unordered_map<string,string> A;
	string temp1,temp2;
	for(int i=0;i<N;i++){
		cin >> temp1 >> temp2;
		A[temp1] = temp2;
	}
	for(int i=0;i<M;i++){
		cin >> temp1;
		cout << A[temp1] << "\n";
	}
	return 0;
}