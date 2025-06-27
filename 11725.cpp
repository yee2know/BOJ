#include <vector>
#include <iostream>
#include <queue>
using namespace std;
static vector<vector<int>> A;
static vector<int> C;
static vector<bool> visited;
void BFS(int v);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	A.resize(N+1);
	C.resize(N+1);
	C[1]=0;
	visited = vector<bool>(N+1,false);
	int t1,t2;
	for(int i=0;i<N;i++){
		cin >> t1 >> t2;
		A[t1].push_back(t2);
		A[t2].push_back(t1);
	}
	BFS(1);
	for(int i=2;i<=N;i++){
		for(int k : A[i]){
			if(C[i]>C[k]){
				cout << k << "\n";
				break;
			}
		}
	}
	return 0;
}

void BFS(int v){
	visited[v] = true;
	queue<int> B;
	B.push(v);

	while(!B.empty()){
		int node = B.front();
		B.pop();
		visited[node]=true;
		for(int k : A[node]){
			if(!visited[k]){
				B.push(k);
				C[k]=C[node]+1;
			}
		}
	}
}