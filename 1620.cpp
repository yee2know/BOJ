#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	vector<string> A(N+1);
	unordered_map<string,int> B;
	string temp;
	for(int i=1;i<=N;i++){
		cin >> temp;
		B[temp]=i;
		A[i]=temp;
	}
	for(int i=0;i<M;i++){
		cin >> temp;
		if(isNumber(temp)){
			cout << A[stoi(temp)] << "\n";
		}else cout << B[temp] << "\n";
	}
	return 0;
}