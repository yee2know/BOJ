#include <vector>
#include <iostream>
using namespace std;

bool check(string &s){
	int l = 0;
	int r = (int)s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

void solve(){
	int N;
	cin >> N;
	vector<string> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			string a = A[i]+A[j];
			if(check(a)){
				cout << a << '\n'; return;
			}
			a = A[j] + A[i];
			if(check(a)){
				cout << a << '\n'; return;
			}
		}
	}
	cout << 0 << '\n';
	return;
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