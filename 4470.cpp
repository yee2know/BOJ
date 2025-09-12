#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin >> n;
	int i=1;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		cout << i <<". " << s << "\n";
		i++;
	}
	return 0;
}