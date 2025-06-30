#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
static int N,M;
static vector<int> A;
static vector<int> B;
static vector<bool> visited;
static vector<int> pre;
void Print(){
	
	bool isSame=true;
	for(int i=1;i<=M;i++){
		if(pre[i]!=B[i]){
			isSame=false;
			break;
		}
	}
	if(isSame==true) return;
	
	for(int i=1;i<=M;i++){
		cout << B[i] << " ";
	}
	cout << "\n";
	for(int i=1;i<=M;i++) pre[i]=B[i];
}

void DFS(int v, int depth){
	if(depth==M){
		Print();
		return;
	}
	int prev=-1;
	for(int i=0;i<N;i++){
		if(!visited[i]){
			if(prev==A[i]) continue;
			prev=A[i];
			visited[i]=true;
			B[depth+1]=A[i];
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
	visited = vector<bool>(N,false);
	B = vector<int>(N+1,0);
	pre = vector<int>(M+1,-1);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	sort(A.begin(),A.end());
	DFS(A[0],0);
	return 0;
}