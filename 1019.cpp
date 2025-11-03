#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
string N;
vector<ll> A;
vector<ll> ten;

ll check(int n,int x){
	ll num = stoll(N);
	ll sum = 1;
	for(int i=1;i<=N.size();i++){
		if(i==n) continue;
		if(i!=N.size()) {
			sum *= 10;
			continue;
		}
		sum *= ((N[N.size()-i]-'0')+1);
	}
	//cout << n << " " << x << " " << sum << "\n";
	return sum;
}
void solve(){
	ll tens=1;
	ten.resize(12);
	for(int i=0;i<12;i++){
		ten[i]=tens;
		tens*=10;
	}
	cin >> N;
	A.assign(10,0);
	for(int i=1;i<=N.size();i++){
		int idx = N.size()-i;
		int num = N[idx]-'0';
		if(i!=N.size()){
			for(int j=0;j<10;j++){
				A[j] += check(i,j);
			}
		}else{
			for(int j=0;j<=num;j++){
				A[j] += check(i,j);
			}
		}
	}
	for(int i=0;i<10;i++) cout << A[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
