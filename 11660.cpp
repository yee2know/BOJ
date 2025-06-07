#include <iostream>
using namespace std;
	int a[1025][1025]={0};
	int b[1025][1025]={0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			b[i][j]= b[i][j-1] + b[i-1][j] - b[i-1][j-1] + a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = b[x2][y2] - b[x1-1][y2] - b[x2][y1-1] + b[x1-1][y1-1];
		cout << result << "\n";
	}
	return 0;
}