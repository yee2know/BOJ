#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n==0) {
			cout << "1 0" << "\n";
			continue;
		}
		else if(n==1) {
			cout << "0 1" << "\n";
			continue;
		}
		int i=2;
		int a[3][2]={{1,0},{0,1},{0,0}};
		while(i<=n){
			a[i%3][0]=a[(i+1)%3][0]+a[(i+2)%3][0];
			a[i%3][1]=a[(i+1)%3][1]+a[(i+2)%3][1];
			i++;
		}
		i--;
		cout << a[i%3][0] << " " << a[i%3][1] << "\n";
	}
	return 0;
}