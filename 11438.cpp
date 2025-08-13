#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

static int N,M;
static vector<vector<int>> tree;
static vector<int> depth;
static int kmax;
static int parent[21][100001];
static vector<bool> visited;
int LCA(int a,int b);
void BFS(int v);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	tree.resize(N+1);
	depth.resize(N+1);
	visited.resize(N+1);

	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int tmp=1;
	kmax=0;
	while(tmp<=N){
		tmp <<=1;
		kmax++;
	}

	BFS(1);

	for(int k = 1; k<=kmax;k++){
		for(int n=1;n<=N;n++){
			parent[k][n]=parent[k-1][parent[k-1][n]];
		}
	}

	cin >> M;

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		int lca = LCA(a,b);
		cout << lca << "\n";
	}
	return 0;
}

int LCA(int a,int b){
	if(depth[a]>depth[b]){
		int tmp=a;
		a=b;
		b=tmp;
	}

	for(int k=kmax;k>=0;k--){
		if(pow(2,k)<=depth[b]-depth[a]){
			if(depth[a]<=depth[parent[k][b]]){
				b=parent[k][b];
			}
		}
	}
	for(int k=kmax;k>=0&&a!=b;k--){
		if(parent[k][a]!=parent[k][b]){
			a=parent[k][a];
			b=parent[k][b];
		}
	}
	int lca=a;
	if(a!=b){
		lca=parent[0][lca];
	}
	return lca;
}

void BFS(int v){
	queue<int> q;
	visited[v]=true;
	q.push(v);
	int level=1;
	int now_size=1;
	int count=0;

	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int next : tree[now]){
			if(!visited[next]){
				visited[next]=true;
				q.push(next);
				parent[0][next]=now;
				depth[next]=level;
			}
		}
		count++;
		if(count==now_size){
			count=0;
			now_size=q.size();
			level++;
		}
	}
}