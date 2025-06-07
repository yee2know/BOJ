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
	vector<char> result;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	stack<int> s;
	int num = 1;
	for(int i=0;i<N;i++){
		int curr = A[i];
		if(curr>=num){
			while(curr>=num){
				s.push(num++);
				result.push_back('+');
			}
			s.pop();
			result.push_back('-');
		}else{
			int n=s.top();
			s.pop();
			if(curr<n){
				cout << "NO";
				return 0;
			}else{
				result.push_back('-');
			}
		}

	}
			for(int i=0;i<result.size();i++){
			cout << result[i] << "\n";
		}
	return 0;
}