#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N,M;
static vector<bool> visited;
vector<int> A;
vector<int> B;

void Print(){
	for(int i=0;i<M;i++){
		cout << B[i] << " ";
	}
	cout << "\n";
}

void DFS(int v,int depth){
	if(depth==M){
		Print();
		return;
	}

	for(int i=0;i<N;i++){
		if(!visited[i]){
			B[depth]=A[i];
			visited[i]=true;
			DFS(A[i],depth+1);
			visited[i]=false;
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	A.resize(N);
	B.resize(N);
	visited = vector<bool>(N,false);
	for(int i=0;i<N;i++) cin >> A[i];
	sort(A.begin(),A.end());
	DFS(A[0],0);
	return 0;
}