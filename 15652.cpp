#include <vector>
#include <iostream>
using namespace std;
int N,M;
int A[9];

void DFS(int v,int depth){
	A[depth]=v;
	if(depth==M){
		for(int i=1;i<=M;i++){
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = v;i<=N;i++){
		DFS(i,depth+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	DFS(1,1);
	return 0;
}