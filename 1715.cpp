#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> A;
	int temp;
	for(int i=0;i<N;i++){
		cin >> temp;
		A.push(temp);
	}
	int d1=0,d2=0,sum=0;
	while(A.size()!=1){
		d1=A.top();
		A.pop();
		d2=A.top();
		A.pop();
		sum+=d1+d2;
		A.push(d1+d2);
	}
	cout << sum;
	return 0;
}