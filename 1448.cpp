#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	priority_queue<int> A;
	int temp;
	for(int i=0;i<N;i++){
		cin >> temp;
		A.push(temp);
	}
	int a,b,c;
	while(A.size()>=3){
		a=A.top();
		A.pop();
		b=A.top();
		A.pop();
		c=A.top();
		A.pop();
		A.push(b); A.push(c);
		if(a>=b+c) continue;
		else{
			cout << a+b+c;
			return 0;
		}
	}
	cout << -1;
	return 0;
}