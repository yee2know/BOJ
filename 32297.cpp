#include <vector>
#include <iostream>
using namespace std;
char gori[] = {'g','o','r','i'};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	string S;
	cin >> S;
	bool isYes=false;
	for(int i=0;i<N-3;i++){
		bool str = true;
		for(int j=0;j<4;j++){
			if(S[i+j]==gori[j]){

			}else{
				str=false;
			}
		}
		if(str) isYes=true;
	}
	if(isYes) cout <<"YES"; 
	else cout << "NO";
	return 0;
}