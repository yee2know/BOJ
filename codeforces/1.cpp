#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,x;
    cin >> t;
    while(t--){
        cin >> x >> n;
        if(n%2==1) cout << x << "\n";
        else cout << "0\n";
    }
	return 0;
}