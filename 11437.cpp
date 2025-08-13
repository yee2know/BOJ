#include <vector>
#include <iostream>
#include <queue>
using namespace std;

static int N,M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;
int LCA(int a, int b);
void BFS(int v);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	tree.resize(N+1);
	depth.resize(N+1);
	parent.resize(N+1);
	visited.resize(N+1);

	for(int i=0;i<N-1;i++){
		int s,e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	BFS(1);
	cin >> M;

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		cout << LCA(a,b) << "\n";
	}
	return 0;
}

int LCA(int a,int b){
	if(depth[a]<depth[b]){
		int tmp=a;
		a=b;
		b=tmp;
	}
	while(depth[a]!=depth[b]){
		a=parent[a];
	}
	while(a!=b){
		a=parent[a];
		b=parent[b];
	}
	return a;
}

void BFS(int v){
	queue<int> q;
	q.push(v);
	visited[v]=true;
	int level=1;
	int now_size=1;
	int count=0;

	while(!q.empty()){
		int now_node = q.front();
		q.pop();
		for(int next : tree[now_node]){
			if(!visited[next]){
				visited[next]=true;
				q.push(next);
				parent[next]=now_node;
				depth[next]=level;
			}
		}
		count++;
		if(count==now_size){
			count=0;
			now_size = q.size();
			level++;
		}
	}
}