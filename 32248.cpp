//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	ll N,T;
	cin >> N >> T;
	vector<int> A(N+1);
	for(int i=1;i<=N;i++) cin >> A[i];
	vector<int> visited(N+1,-1);
	vector<int> path(N);	
	int i = 0;
	int now = 1;
	while(visited[now]==-1){
		path[i]=now;
		visited[now] = i++;
		now = A[now];
	}
	int start = visited[now];
	int len = i - start;
	if(T<start){
		cout << path[T];
		return;
	}else{
		ll idx = (T-start)%len;
		cout << path[start+idx];
		// 1 3 2
		// i = 3
		// now = 2
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