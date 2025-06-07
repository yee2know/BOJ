#include <iostream>
using namespace std;
int word[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>96) s[i]-=32;
		word[s[i]-'A']++;
		i++;
	}
	int max=word[0],ind=0;
	for(int i=0;i<26;i++) if(max<word[i]) {
		max=word[i];
		ind=i;
	}
	int counter=0;
	for(int i=0;i<26;i++) if(max==word[i]) counter++;
	if(counter>1) cout << "?";
	else cout << (char)(ind+'A');
	return 0;
}