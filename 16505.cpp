//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static bool A[2000][2000];

void makeStar(int N,int x,int y){
	if(N==1){
		A[x][y] = A[x+1][y] = A[x][y+1] = true;
		return;
	}

	makeStar(N-1,x,y);
	makeStar(N-1,x+(1<<(N-1)),y);
	makeStar(N-1,x,y+(1<<(N-1)));
}

void solve(){
	int N;
	cin >> N;
	if(N==0){
		cout << "*";
		return;
	}
	makeStar(N,0,0);
	ll powN = 1<<N;
	for(int i=0;i<powN;i++){
		for(int j=0;j<powN-i;j++){
			if(A[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}