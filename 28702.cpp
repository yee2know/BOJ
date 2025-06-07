#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string strnum(int n){
	if(n%15==0) return "FizzBuzz";
	else if(n%5==0) return "Buzz";
	else if(n%3==0) return "Fizz";
	return to_string(n);
}
int isNum(string s){
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) continue;
		return 0;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A[3];
	int B[3];
	for(int i=0;i<3;i++) {
		cin >> A[i];
		if(isNum(A[i])){
			cout << strnum(stoi(A[i])+3-i);
			return 0;
		}
	}
	for(int i=0;i<3;i++){
		string a=A[i];
		if(a=="FizzBuzz") B[i]=15;
		else if(a=="Fizz") B[i]=3;
		else B[i] = 5;
	}
	int i=1;
	while(1){
		if((i*B[0]+1)%B[1]&&(i*B[0]+2)%B[2]){
			cout << strnum(i*B[0]+3);
		}
		i++;
	}
	return 0;
}