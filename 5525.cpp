#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	string S;
	cin >> N >> M >> S;
	int IOI=0;
	int count=0;
	char prev='T';
	for(int i=0;i<M;i++){
		if(prev!=S[i]){
			IOI++;
			if(IOI>=N*2+1&&IOI%2==1) count++;
		}else {
			if(S[i]=='I') IOI=1;
			else IOI=0;
		}
		prev=S[i];
	}
	cout << count;
	return 0;
}