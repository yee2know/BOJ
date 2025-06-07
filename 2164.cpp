#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int o=0;
	int N;
	cin >> N;
	queue<int> A;
	for(int i=1;i<=N;i++){
		A.push(i);
	}
	while(A.size()>1){
		if(o==0) 
		{
			A.pop();
			o=1;
		}else if(o==1){
			A.push(A.front());
			A.pop();
			o=0;
		}
	}
	cout << A.front();
	return 0;
}