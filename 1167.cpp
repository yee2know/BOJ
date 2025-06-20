#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static vector<vector<pair<int,int>>> A;
static vector<bool> Visited;
static vector<int> Distance;
void BFS(int v);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V;
	cin >> V;
	A.resize(V+1);
	Visited = vector<bool>(V+1,false);
	Distance = vector<int>(V+1,0);
	for(int i=0;i<V;i++){
		int vertex,temp1=0,temp2;
		cin >> vertex;
		while(temp1!=-1){
			cin >> temp1;
			if(temp1!=-1){
			cin >> temp2;
			A[vertex].push_back(make_pair(temp1,temp2));
			}
		}
	}
	BFS(1);
	int max=0,maxindex=0;
	for(int i=0;i<V;i++){
		if(Distance[i+1]>max) {
			max= Distance[i+1];
			maxindex=i+1;
		}
	}
	fill(Visited.begin(),Visited.end(),false);
	fill(Distance.begin(),Distance.end(),0);
	BFS(maxindex);
	max=0;
	for(int i=0;i<V;i++){
		if(Distance[i+1]>max) {
			max= Distance[i+1];
		}
	}
	cout << max;
	return 0;
}

void BFS(int v){
	queue<int> MyQueue;
	MyQueue.push(v);
	Visited[v]=true;

	while(!MyQueue.empty()){
		int now = MyQueue.front();
		MyQueue.pop();
		Visited[now]=true;
		for(int i=0;i<A[now].size();i++){
			if(!Visited[A[now][i].first]){
				Distance[A[now][i].first] = Distance[now]+A[now][i].second;
				MyQueue.push(A[now][i].first);
			}
		}
	}
}