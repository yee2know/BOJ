#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a=1;
	string s1,s2;
	int min1=0,max1=11;
	while(true){
		cin >> a;
		if(a==0)return 0;
		else{
			cin >> s1 >> s2;
			if(s1=="too") {
				if(s2=="low") min1 = max(min1,a);
				else max1 = min(max1,a);
			}
			else{
				if(min1<a&&a<max1) cout << "Stan may be honest\n";
				else cout << "Stan is dishonest\n";
				min1=0;max1=11;
			}
		}
	}
	return 0;
}