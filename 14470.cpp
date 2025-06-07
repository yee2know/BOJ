#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	int sec=0;
	if(a<0){
		sec += a*c*(-1);
		a=0;
	}
	if(a==0){
		sec += d;
	}
	sec += (b-a)*e;
	cout << sec;
	return 0;
}