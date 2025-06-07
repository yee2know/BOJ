#include <iostream>
using namespace std;
int myArr[4], checkArr[4];
int check=0;
void add(char a){
	switch (a){
		case 'A':
			myArr[0]++;
			if(myArr[0]==checkArr[0]) check++;
			break;
		case 'C':
			myArr[1]++;
			if(myArr[1]==checkArr[1]) check++;
			break;
		case 'G':
			myArr[2]++;
			if(myArr[2]==checkArr[2]) check++;
			break;
		case 'T':
			myArr[3]++;
			if(myArr[3]==checkArr[3]) check++;
			break;
	}
}
void rem(char a){
	switch (a){
		case 'A':
			if(myArr[0]==checkArr[0]) check--;
			myArr[0]--;
			break;
		case 'C':
		if(myArr[1]==checkArr[1]) check--;
		myArr[1]--;
			break;
		case 'G':
		if(myArr[2]==checkArr[2]) check--;
		myArr[2]--;
			break;
		case 'T':
		if(myArr[3]==checkArr[3]) check--;
		myArr[3]--;
			break;
	}
}

int main() {
	int S,P,A[4];
	int count=0;
	cin >> S >> P;
	string s;
	cin >> s;
	for(int i=0;i<4;i++){
		cin >> checkArr[i];
		if(checkArr[i]==0) check++;
	}
	for(int i=0;i<P;i++){
		add(s[i]);
	}
	if(check==4){
		count++;
	}
	for(int i=P;i<S;i++){
		int j=i-P;
		add(s[i]);
		rem(s[j]);
		if(check==4){
		count++;
	}
	}
	cout << count;
	return 0;
}