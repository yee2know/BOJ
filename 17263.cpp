#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,max=0,temp;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		if(max<temp) max=temp;
	}
	cout << max;
	return 0;
}