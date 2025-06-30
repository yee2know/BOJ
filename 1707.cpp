#include <vector>
#include <iostream>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int K;
	cin >> K;
	while(K--){
		int V,E;
		cin >> V >> E;
		A.resize(V+1);
		visited = vector<bool>(V+1,false);
		for(int i=0;i<E;i++){
			int a,b;
			cin >> a >> b;
			A[a].push_back(b);
			A[b].push_back(a);
		}

		
	}
	return 0;
}