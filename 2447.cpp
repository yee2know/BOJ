//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static bool A[7000][7000];

void printArr(ll M){
	for(int i=1;i<M+1;i++){
		for(int j=1;j<M+1;j++){
			if(A[i][j]) cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}

void makeStar(ll N,int x,int y){
	if(N==3){
		A[x][y] = A[x-1][y] = A[x-2][y] =A[x][y-1]=A[x-2][y-1]=
		A[x][y-2]=A[x-1][y-2]=A[x-2][y-2]=true;
	}else{
		ll M = N/3;
		makeStar(M,x,y);
		makeStar(M,x-M,y);
		makeStar(M,x-2*M,y);
		makeStar(M,x,y-M);
		makeStar(M,x,y-2*M);
		makeStar(M,x-M,y-2*M);
		makeStar(M,x-2*M,y-M);
		makeStar(M,x-2*M,y-2*M);
	}
}

void solve(){
	ll N;
	ll M;
	cin >> N;
	M=N;
	int pow = 0;
	while(N>1){
		N/=3;
		pow++;
	}
	makeStar(M,M,M);
	printArr(M);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}