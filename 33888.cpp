#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> A(N+1);
	vector<int> indegree(N+1,0);
	for(int i=0;i<N+3;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
		indegree[a]++;
		indegree[b]++;
	}
	int a,b,c,d,e,f;
	vector<int> abd;
	vector<int> ce;
	for(int i=1;i<=N;i++){
		if(indegree[i]==1) f=i;
		else if(indegree[i]==4) ce.push_back(i);
		else if(indegree[i]==3) abd.push_back(i);
	}
	queue<int> q;
	queue<int> candidate;
	vector<bool> visited(N+1,false);
	q.push(f);
	visited[f]=true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(find(ce.begin(),ce.end(),now)!=ce.end()){
			e=now;
			break;
		}
		for(int i : A[now]){
			if(!visited[i]){
				visited[i]=true;
				q.push(i);
			}
		}
	}
	if(ce[0]==e) c=ce[1];
	else c= ce[0];
	fill(visited.begin(),visited.end(),false);
	while(!q.empty()) q.pop();
	visited[c]=true;
	visited[e]=true;
	q.push(e);
	while(!q.empty()){
		int now = q.front();
		q.pop();

		for(int i : A[now]){
			if(!visited[i]){
				if(find(abd.begin(),abd.end(),i)!=abd.end()){
					candidate.push(i);
					visited[i]=true;
					continue;
				}
				visited[i]=true;
				q.push(i);
			}
		}
	}
	int tmp = candidate.front(); candidate.pop();
	int tmp1 = candidate.front();
	d = max(tmp,tmp1);
	b = min(tmp,tmp1);
	for(int i=0;i<3;i++){
		if(abd[i]!=b&&abd[i]!=d) a = abd[i];
	}
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f;
	return 0;
}