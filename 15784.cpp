#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,A,B;
	cin >> N >> A >> B;
	int S[1000][1000];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> S[i][j];
		}
	}
	bool isHappy=true;
	for(int i=0;i<N;i++) if(S[i][B-1]>S[A-1][B-1]) isHappy=false;
	for(int j=0;j<N;j++) if(S[A-1][j]>S[A-1][B-1]) isHappy=false;
	if(isHappy) cout << "HAPPY";
	else cout << "ANGRY";
	return 0;
}