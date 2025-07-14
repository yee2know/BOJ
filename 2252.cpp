#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	vector<vector<int>> A(N+1);
	vector<int> degree(N+1,0);

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		degree[b]++;
	}
	queue<int> B;
	for(int i=1;i<=N;i++){
		if(degree[i]==0)
			B.push(i);
	}

	while(!B.empty()){
		int a = B.front();
		B.pop();
		cout << a << " ";
		for(int i : A[a]){
			degree[i]--;
			if(degree[i]==0)
				B.push(i);
		}
	}
	return 0;
}