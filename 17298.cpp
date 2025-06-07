#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N,0);
	vector<int> result(N,0);
	stack<int> B;
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++){
		while(!B.empty()&&A[B.top()]<A[i]){
			result[B.top()]=A[i];
			B.pop();
		}
		B.push(i);
	}
	while(!B.empty()){
		result[B.top()]=-1;
		B.pop();
	}
	for(int i=0;i<N;i++){
		cout << result[i] << " ";
	}
	return 0;
}
// 3
//