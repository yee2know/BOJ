//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

static bool visited[4000][4000];

void solve(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	int x=2000,y=2000;
	visited[x][y]=true;
	int cnt=1;
	for(int i=0;i<N;i++){
		char s = S[i];
		if(s=='S') x--;
		else if(s=='N') x++;
		else if(s=='E') y++;
		else y--;
		if(!visited[x][y]){
			cnt++;
			visited[x][y]=true;
		}
	}
	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}