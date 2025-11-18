//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
typedef pair<int,string> num;
int D(int x){
	x*=2;
	x%=10000;
	return x;
}

int S(int x){
	x-=1;
	return ((x==-1)?9999:x);
}

int L(int x){
	int a = x/1000;
	x*=10;
	x%=10000;
	x+=a;
	return x;
}

int R(int x){
	int a = x%10;
	x/=10;
	x+= a*1000;
	return x;
}

void solve(){
	int N,M;
	cin >> N >> M;
	queue<num> q;
	vector<bool> visited(10001,false);
	q.push({N,""});
	visited[N] = true;
	while(!q.empty()){
		num now = q.front();
		if(now.first==M) {
			cout << now.second << '\n';
			return;
		}
		q.pop();
		int n = now.first;
		string s = now.second;
		if(!visited[D(n)]){
			q.push({D(n),s+'D'});
			visited[D(n)]=true;
		}
		if(!visited[S(n)]){
			q.push({S(n),s+'S'});
			visited[S(n)]=true;
		}
		if(!visited[L(n)]){
			q.push({L(n),s+'L'});
			visited[L(n)]=true;
		}
		if(!visited[R(n)]){
			q.push({R(n),s+'R'});
			visited[R(n)]=true;
		}

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--)
    solve();
	return 0;
}