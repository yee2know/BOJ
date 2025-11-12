//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int getpi(string P){
	int N = P.size();
	int j = 0;
	vector<ll> pi(N,0);
	for(int i=1;i<N;i++){
		while(j>0&&P[i]!=P[j])
			j = pi[j-1];
		if(P[i]==P[j]){
			pi[i] = ++j;
		}
	}
	return pi[N-1];
}



void solve(){
	string S;
	while(true){
		getline(cin,S);
		if(S==".") return;
		int pi = getpi(S);
		int N=S.size();
		int an = N-pi;
		if(N%an==0) cout << N/an << '\n';
		else cout << 1 << '\n';
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