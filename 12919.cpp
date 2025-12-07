//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

string popA(string S){
	S.pop_back();
	return S;
}

string popB(string &S){
	int s =0;
	int e =S.size()-1;
	while(s<=e){
		swap(S[s],S[e]);
		s++;
		e--;
	}
	S.pop_back();
	return S;
}

void solve(){
	string S,T;
	cin >> S >> T;
	queue<string> q;
	q.push(T);
	while(!q.empty()){
		string now = q.front();
		q.pop();
		if(now==S){
			cout << 1;
			return;
		}

		if(now.size()>S.size()){
			if(now.back()=='A') q.push(popA(now));
			if(now.front()=='B') q.push(popB(now));
		}
	}
	cout << 0;
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