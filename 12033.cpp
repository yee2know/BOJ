//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static vector<ll> A;
static vector<bool> visited;
static ll N;
static ll cnt;
ll Find(ll n){
	for(ll i=0;i<N*2;i++){
		if(A[i]==n&&!visited[i]) return i;
	}
}

void solve(){	
	cin >> N;
	A.resize(N*2);
	visited.assign(N*2,false);
	vector<ll> answer;
	for(ll i=0;i<N*2;i++) cin >> A[i];
	for(ll i=0;i<N*2;i++){
		if(!visited[i]){
			answer.push_back(A[i]);
			visited[Find(A[i]*4/3)] = visited[i] = true;
		}
	}
	cout << "Case #" << cnt << ": ";
	for(ll i=0;i<answer.size();i++){
		cout << answer[i] << " ";
	}
	cout << "\n";
	cnt++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cnt=1;
	while(n--)
    solve();
	return 0;
}