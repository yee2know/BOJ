//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

static vector<string> A;
static int N,M;

bool check(int x,int y);

void solve(){
	cin >> N >> M;
	A.resize(N);
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(check(i,j)){
				cout << 1;
				return;
			}
		}
	}
	cout << 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}

bool check(int x,int y){
	if(x+1<N&&y+1<M){
		bool result = true;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(A[x+i][y+j]=='0') result=false;
			}
		}
		return result;
	}
	return false;
}