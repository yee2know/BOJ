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
	cout << a+b-c << "\n";
	cout << stoi(to_string(a)+to_string(b))-c;
	return 0;
}