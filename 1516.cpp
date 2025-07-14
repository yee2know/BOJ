#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> A(N+1);
	vector<int> degree(N+1,0);
	vector<int> time(N+1);
	vector<int> Ttime(N+1,0);
	for(int i=1;i<=N;i++){
		cin >> time[i];
		int a;
		while(1){
			cin >> a;
			if(a==-1) break;
			A[a].push_back(i);
			degree[i]++;
		}
	}
	queue<int> B;
	for(int i=1;i<=N;i++){
		if(degree[i]==0)
			B.push(i);
	}
	while(!B.empty()){
		int now = B.front();
		B.pop();

		for(int i : A[now]){
			degree[i]--;
			Ttime[i]=max(Ttime[now]+time[now],Ttime[i]);
			if(degree[i]==0){
				B.push(i);
			}
		}
	}
	for(int i=1;i<=N;i++){
		cout << Ttime[i] + time[i] << "\n";
	}
	return 0;
}