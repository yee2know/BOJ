#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c;
	cin >> a >> b >> c;
	c-=a;
	if(c%b!=0||c/b<0) cout << "X";
	else cout <<c/b+1;
	return 0;
}