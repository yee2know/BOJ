#include <vector>
#include <iostream>
using namespace std;
static vector<int> parent;
static vector<int> trueP;
static vector<vector<int>> party;
static int result;

int Find(int a){
	if(a==parent[a]) return a;
	else{
		return parent[a]= Find(parent[a]);
	}
}
void Union(int a,int b){
	a= Find(a);
	b= Find(b);
	if(a!=b){
		parent[b]=a;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M,T;
	cin >> N >> M >> T;
	parent.resize(N+1);
	party.resize(M);
	trueP.resize(T);
	for(int i=0;i<T;i++){
		cin >> trueP[i];
	}
	for(int i=0;i<M;i++){
		int partySize;
		cin >> partySize;
		for(int j=0;j<partySize;j++){
			int tmp;
			cin >> tmp;
			party[i].push_back(tmp);
		}
	}
	for(int i=0;i<=N;i++) parent[i]=i;
	for(int i=0;i<M;i++){
		for(int j=1;j<party[i].size();j++){
			Union(party[i][0],party[i][j]);
		}
	}
	for(int i=0;i<M;i++){
		bool isPossible=true;
		int cur=party[i][0];
		for(int j=0;j<T;j++){
			if(Find(cur)==Find(trueP[j])){
				isPossible=false;
				break;
			}
		}
		if(isPossible) result++;
	}
	cout << result;
	return 0;
}