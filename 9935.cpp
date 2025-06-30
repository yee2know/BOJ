#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,b;
	cin >> s;
	cin >> b;
	for(int i=0;i<s.size();i++){
		if(s[i]==b[0]){
			bool isBomb=true;
			int j=0;
			while(j<b.size()){
				if(s[i+j]=='*') {
					i++;
					continue;
				}
				if(s[i+j]==b[j]){

				}else{
					isBomb=false;
					break;
				}

				j++;
			}
		}
	}
	return 0;
}