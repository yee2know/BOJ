#include <vector>
#include <iostream>
using namespace std;
static vector<int> parent;
int Find(int i){
	if(parent[i]==i) return i;
	return parent[i]=Find(parent[i]);
}

void Union(int a,int b){
	a = Find(a);
	b = Find(b);
	if(a!=b){
		parent[b]=a;
	}
}

void solve(){
	int G,P;
	cin >> G >> P;
	parent.resize(G+1);
	for(int i=0;i<=G;i++) parent[i]=i;
	int result=0;
	for(int i=0;i<P;i++){
		int a;
		cin >> a;
		if(Find(a)==0){
			cout << result;
			return;
		}else{
			Union(Find(a)-1,a);
			result++;
		}
	}
	// 0 1 1
	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}