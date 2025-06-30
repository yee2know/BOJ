#include <queue>
#include <vector>
#include <iostream>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
static vector<int> answer;
void BFS(int v);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	A.resize(N+1);
	visited = vector<bool>(N+1,false);
	answer.resize(N+1);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
	}
	for(int i=1;i<=N;i++){
		BFS(i);
		fill(visited.begin(),visited.end(),false);
	}
	int max=0;
	int ind;
	for(int i=1;i<=N;i++){
		if(max<answer[i]){
			max =answer[i];
		}
	}
	for(int i=1;i<=N;i++){
		if(max==answer[i]){
			cout << i << " ";
		}
	}
	return 0;
}

void BFS(int v){
	visited[v] = true;
	queue<int> MyQueue;
	MyQueue.push(v);

	while(!MyQueue.empty()){
		int node = MyQueue.front();
		MyQueue.pop();

		for(int i : A[node]){
			if(!visited[i]){
				visited[i]=true;
				answer[i]++;
				MyQueue.push(i);
			}
		}
	}
}