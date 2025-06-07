#include <iostream>
using namespace std;

int main() {
	int n,m;
	int i,j;
	int a[100001]={0},b[100001]={0};
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int k=0;k<m;k++){
		cin >> i >> j;
		cout << b[j]-b[i-1] << "\n";
	}
	return 0;
}