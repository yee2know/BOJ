#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	if(n<5){
		cout << 4;
		return 0;
	}
	int prev=1,curr=1;
	while(curr*curr<=n){
		prev=curr;
		curr++;
	}
	int x = prev-1;
	int y = (prev+(n-prev*prev+prev-1)/prev-1);
	cout << x*2+y*2;
	return 0;
}

/*
17

...
...
...

*/