//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static char star[4000][4000];

int pow(int n){
	int res = 1;
	while(n--){
		res*=5;
	}
	return res;
}

void draw(int N,int i,int j){
	if(N==0) {
		star[i][j]='*';
		return;
	}

	int K = pow(N-1);
									      draw(N-1,i,j);
								          draw(N-1,i+K,j);
draw(N-1,i+2*K,j-2*K);draw(N-1,i+2*K,j-K);draw(N-1,i+2*K,j);draw(N-1,i+2*K,j+K);draw(N-1,i+2*K,j+2*K);
				  	  draw(N-1,i+3*K,j-K);draw(N-1,i+3*K,j);draw(N-1,i+3*K,j+K);
				  	  draw(N-1,i+4*K,j-K);			  	    draw(N-1,i+4*K,j+K);
}

void solve(){
	int N;
	cin >> N;
	int K = pow(N);
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			star[i][j]= ' ';
		}
	}
	draw(N,0,(K/2));
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			cout << star[i][j];
		}
		cout << '\n';
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}