#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	vector<vector<pair<int,int>>> A(N+1);
	vector<vector<pair<int,int>>> B(N+1);
	vector<int> indegree(N+1,0);
	for(int i=0;i<M;i++){
		int a,b,d;
		cin >> a >> b >> d;
		A[a].push_back(make_pair(b,d));
		B[b].push_back(make_pair(a,d));
		indegree[b]++;
	}

	int start,end;
	cin >> start >> end;
	queue<int> q;
	q.push(start);
	vector<int> result(N+1,0);

	while(!q.empty()){
		int now = q.front();
		q.pop();

		for(pair<int,int> next : A[now]){
			indegree[next.first]--;
			result[next.first] = max(result[next.first],result[now]+next.second);
			if(indegree[next.first]==0){
				q.push(next.first);
			}
		}
	}

	int counter=0;
	vector<bool> visited(N+1,false);
	q.push(end);
	visited[end]=true;

	while(!q.empty()){
		int now = q.front();
		q.pop();

		for(pair<int,int> next : B[now]){
			if(next.second+result[next.first]==result[now]){
				counter++;
				if(!visited[next.first]){
					visited[next.first]=true;
					q.push(next.first);
				}
			}
		}
	}
	cout << result[end] << "\n" << counter;
	return 0;
}