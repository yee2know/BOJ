#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,f;
	cin >> n >> f;
	n/=100;
	n*=100;
	int i=0;
	while(true){
		if((n+i)%f==0){
			if(i<10) cout << "0" << i;
			else cout << i;
		}
		i++;
	}
	return 0;
}