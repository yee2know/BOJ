#include <vector>
#include <iostream>
using namespace std;
static vector<int> parent;
static vector<bool> visited;
static vector<bool> processed;
static int result;
void check(int x){
	if(processed[x]) return;
	if(visited[x]){
		processed[x]=true;
		result++;
	}
	visited[x]=true;
	check(parent[x]);
	processed[x]=true;
	visited[x]=false;
}

void solve(){
	int N;
	result=0;
	cin >> N;
	parent.resize(N+1);
	visited.assign(N+1,false);
	processed.assign(N+1,false);
	for(int i=0;i<N;i++) cin >> parent[i+1];
	for(int i=1;i<=N;i++) check(i);
	cout << N-result << "\n";
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