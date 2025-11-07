#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int H,W,K;
	cin >> H >> W >> K;
	int front=0,back=1;
	string a = "";
	while(K--){
		front++;
		if(front>H){
			front = 1;
			back++;
		}
	}
	if(back/10==0) a = "0";
	cout << front << a << back << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--) solve();
	return 0;
}