#include <vector>
#include <iostream>
using namespace std;
static vector<vector<int>> A;
static vector<int> answer;
static int N,M;
void DFS(int v,int depth);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	A.resize(N+1);
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			A[i].push_back(j);
		}
	}
	for(int i=1;i<=N;i++){
		while(!answer.empty()){
			answer.pop_back();
		}
		DFS(i,1);
	}
	return 0;
}
// 1 2  
// 3 4
void DFS(int v,int depth){
	answer.push_back(v);
	if(depth==M){
		for(int i=0;i<answer.size();i++){
			cout << answer[i] << " ";
		}
		cout << "\n";
		answer.pop_back();
		return;
	}
	if(A[v].empty()){
		answer.pop_back();
		return;
	}
	
	for(int i : A[v]){
			DFS(i,depth+1);
			if(i==N) answer.pop_back();
	}
}
// 1 : 2 3 4
// 2 : 3 4
// 3 : 4
// 4 :