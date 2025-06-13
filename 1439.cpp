#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int zero=0,one=0;
	int prev=-1;
	for(int i=0;i<s.size();i++){
		if(prev!=-1&&prev!=s[i]){
			if(s[i]=='0') zero++;
			else one++;
		}else if(prev==-1){
			if(s[i]=='0') zero++;
			else one++;
		}
		prev=s[i];
	}
	cout << min(zero,one);
	return 0;
}