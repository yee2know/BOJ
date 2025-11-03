#include <vector>
#include <iostream>
using namespace std;
vector<int> parent;
typedef pair<int,int> kids;
int Find(int a){
	if(parent[a]==a) return a;
	return parent[a]=Find(parent[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);

	if(a!=b) parent[b]=a;
}

void solve(){
	int N,M,K;
	cin >> N >> M >> K;
	vector<int> candy(N+1);
	parent.resize(N+1);
	for(int i=1;i<=N;i++){
		cin >> candy[i];
		parent[i]=i;
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		Union(a,b);
	}
	vector<vector<int>> A(N+1);
	for(int i=1;i<=N;i++){
		A[Find(i)].push_back(candy[i]);
	}
	vector<kids> kidsGroup;
	for(int i=1;i<=N;i++){
		int people=0;
		int candies=0;
		for(int j : A[i]){
			candies+=j;
			people++;
		}
		if(people!=0){
			kidsGroup.push_back({people,candies});
		}
	}
	vector<int> D(K,0);
	for(int i=0;i<kidsGroup.size();i++){
		int people = kidsGroup[i].first;
		int candies = kidsGroup[i].second;
		for(int j=K-1;j>=people;j--){
			D[j] = max(D[j],D[j-people]+candies);
		}
	}
	int maxV=0;
	for(int i=0;i<K;i++){
		maxV = max(maxV,D[i]);
	}
	cout << maxV;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}