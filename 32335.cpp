#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	string S;
	cin >> S;
	int i=0;
	while(i<N&&M>0){
		int now = S[i]-'0';
		if(now==0){
			i++;
			continue;
		}else if(now+M>=10){
			M -= (10-now);
			S[i++] = '0';
		}else i++;
	}
	if(M>0) S[N-1]+=(M%10);
	cout << S;
	return 0;
}