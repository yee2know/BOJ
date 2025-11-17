//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

static vector<int> parent;
static vector<int> level;
static vector<vector<int>> link;
void setTree(int node,int pnode){
	parent[node] = pnode;
	level[node]= level[pnode]+1;

	for(int i : link[node]){
		if(i==pnode) continue;
		setTree(i,node);
	}
}

void solve(){
	int N;
	cin >> N;
	vector<bool> roots(N+1);
	link.assign(N + 1, vector<int>()); 
    parent.assign(N + 1, 0);
    level.assign(N + 1, 0);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
		roots[b]=true;
	}
	int root;
	for(int i=1;i<=N;i++){
		if(!roots[i]){
			root=i;
			break;
		}
	}
	setTree(root,0);
	int a,b;
	cin >> a >> b;
	if(level[a]<level[b]) swap(a,b);
	while(level[a]!=level[b]) a= parent[a];
	while (a != b) {
        a = parent[a];
        b = parent[b];
    }
	cout << a << "\n";
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