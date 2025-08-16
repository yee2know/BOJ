#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,R,Q;
	cin >> N >> R >> Q;
	vector<int> parent(N+1,0);
	vector<int> depth(N+1, -1);
	parent[R]=-1; //root
	depth[R] = 0;
	vector<vector<int>> tree;
	tree.resize(N+1);
	vector<bool> visited(N+1,false);
	vector<int> leaf;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	//bfs를 진행해 parent 채워주기
	queue<int> q;
	q.push(R);
	visited[R]=true;

	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(tree[now].size()==1&&tree[now][0]==parent[now]) leaf.push_back(now); //
		for(int next : tree[now]){
			if (depth[next] == -1) {
            	depth[next] = depth[now] + 1;
            	parent[next] = now;
            	q.push(next);
        }
		}
	}
	priority_queue<pair<int,int>> q2;
	vector<int> subtree(N+1,1);
	fill(visited.begin(),visited.end(),false);
	for(int i : leaf) {
		q2.push({depth[i],i});
	}
	while(!q2.empty()){
		pair<int,int> now = q2.top();
		q2.pop();

		if(parent[now.second]!=-1){
			subtree[parent[now.second]]+=subtree[now.second];
			if(!visited[parent[now.second]])
			q2.push({depth[parent[now.second]],parent[now.second]});
			visited[parent[now.second]]=true;
		}
	}
	for(int i=0;i<Q;i++){
		int p;
		cin >> p;
		cout << subtree[p] << "\n";
	}
	return 0;
}