#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int temp;
	priority_queue<int,vector<int>,less<int>> A;
	for(int i=0;i<N;i++){
		cin >> temp;
		if(temp==0){
			if(A.empty()){
				cout << 0 << "\n";
			}else{
				cout << A.top() << "\n";
				A.pop();
			}
		}else{
			A.push(temp);
		}
	}
	return 0;
}