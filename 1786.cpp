//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> getPi(string P){
	int N = P.size();
	vector<ll> Pi(N,0);
	int j=0;
	for(int i=1;i<N;i++){
		while(j>0&&P[i]!=P[j]){
			j =Pi[j-1];
		}
		if(P[i]==P[j]){
			Pi[i] = ++j;
		}
	}
	return Pi;
}

vector<ll> kmp(string T,string P){
	vector<ll> ans;
	vector<ll> pi = getPi(P);
	int N = T.size(),M=P.size(),j=0;
	for(int i=0;i<N;i++){
		while(j>0&&T[i]!=P[j])
			j = pi[j-1];
		if(T[i]==P[j]){
			if(j==M-1){
				ans.push_back(i-M+2);
				j = pi[j];
			}else{
				j++;
			}
		}
	}
	return ans;
}

void solve(){
	string T,P;
	getline(cin,T);
	getline(cin,P);
	vector<ll> ans = kmp(T,P);
	cout << ans.size() << '\n';
	for(ll i : ans){
		cout << i << ' ';
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