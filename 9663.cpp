//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
static int cnt;
typedef pair<int,int> board;
static vector<int> A;
static int N;
bool check(int r,int c){
	for(int i=0;i<N;i++){
		if(A[i]==-1) continue;
		if(A[i]==c) return false;
		if(abs(i-r)==abs(A[i]-c)) return false;
	}
	return true;
}

void dfs(int r){
	//cout << r << "\n";
	if(r==N){
		cnt++;
		return;
	}
	for(int i=0;i<N;i++){
		if(check(r,i)){
			A[r]=i;
			dfs(r+1);
			A[r]=-1;
		}
	}
}


void solve(){
	cin >> N;
	cnt=0;
	A.assign(N,-1);
	dfs(0);
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