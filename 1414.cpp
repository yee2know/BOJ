#include <vector>
#include <queue>
#include <iostream>
using namespace std;
static int N;
static vector<int> parent;

typedef struct Edge {
	int s,e,v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

int find(int a){
	if (a==parent[a]) return a;
	else{
		return parent[a] = find(parent[a]);
	}
}

void Union(int a,int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		parent[b]=a;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int sum =0;
	priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0;j<N;j++){
			if(s[j]!='0'){
				if(s[j]>='a'&&s[j]<='z') s[j]= s[j]-'a'+1;
				else if(s[j]>='A'&&s[j]<='Z') s[j]= s[j]-'A'+27;
				sum+=s[j];
				if(i!=j) pq.push({i+1,j+1,s[j]});
			}
		}
	}
	parent.resize(N+1);
	for(int i=0;i<=N;i++) parent[i]=i;
	int ue=0;
	int result=0;
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();

		if(find(now.s)!=find(now.e)){
			Union(now.s,now.e);
			result+=now.v;
			ue++;
		}
	}
	if(ue==N-1) cout << sum-result;
	else cout << -1;
	return 0;
}