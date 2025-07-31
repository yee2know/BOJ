#include <vector>
#include <iostream>
using namespace std;
static int N,del,answer;
static vector<bool> visited;
static vector<vector<int>> tree;
void DFS(int v);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	visited = vector<bool>(N,false);
	tree.resize(N);
	int root;
	for(int i=0;i<N;i++){
		int tmp;
		cin >> tmp;
		if(tmp==-1){
			root=i;
			continue;
		}
		tree[tmp].push_back(i);
	}
	cin >> del;
	if(del!=root) DFS(root);
	if(tree[root].size()==1&&tree[root][0]==del) answer++;
	cout << answer;
	return 0;
}
void DFS(int v){
	visited[v]=true;

	for(int i : tree[v]){
		if(i!=del&&!visited[i]){
			if(tree[i].empty()||tree[i].size()==1&&tree[i][0]==del) answer++;
			DFS(i);
		}
	}
}