#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	double x1,y1,x2,y2,r1,r2;
	double d1,d2;
	cin >> n;
	while(n--){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if(x1==x2&&y1==y2&&r1==r2){
			cout << -1 << "\n";
			continue;
		}
		d1=r1+r2;
		d2 = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		if(d1>d2){
			cout << 2 << "\n";
			continue;
		}else if(d1<d2){
			cout << 0 << "\n";
			continue;
		}else{
			cout << 1 << "\n";
		}
	}
	return 0;
}