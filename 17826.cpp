#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int A[50];
	int S;
	for(int i=0;i<50;i++) cin >> A[i];
	cin >> S;
	int k;
	for(int i=0;i<50;i++){
		if(A[i]==S) k =i;
	}
	k++;
	if(k<=5) cout << "A+";
	else if(k<=15) cout << "A0";
	else if(k<=30) cout << "B+";
	else if(k<=35) cout << "B0";
	else if(k<=45) cout << "C+";
	else if(k<=48) cout << "C0";
	else cout << "F";
	return 0;
}