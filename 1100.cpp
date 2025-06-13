#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s[8];
	for(int i=0;i<8;i++) cin >> s[i];
	int a=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(s[i][j]=='F'&&(i+j)%2==0) a++;
		}
	}
	cout << a;
	return 0;
}