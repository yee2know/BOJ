#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int x=20000,A=20000;
	int temp=20000;
	int cur=1;
	for(int i=0;i<s.size();i++){
		char a = s[i];
		if(a=='-') cur=-1;
		else if(a>='0'&&a<='9'){
			if(temp==20000) temp = a-'0';
			else{
				temp*=10;
				temp+= a-'0';
			}
		}
		else if(a=='x') {
			x = temp*cur;
			temp=20000;
			cur=1;
		}
	}
	if(x==20000){
		if(temp==0) cout << "W";
		else if(temp*cur==1) cout << "x+W";
		else if(temp*cur==-1) cout << "-x+W";
		else{
			cout << temp*cur<<"x+W";
		}
	}else{
		if(x/2==1) cout << "xx";
		else if(x/2==-1) cout << "-xx";
		else cout << x/2 << "xx";
		if(temp!=20000){
			if(cur==1){
				cout<<"+";
				if(temp==1) cout << "x";
				else cout <<temp<<"x";
			}else{

				cout<<"-";
				if(temp==1) cout << "x";
				else cout << temp<<"x";
			}
		}
		cout << "+W";
	}
	return 0;
}