#include <iostream>
#include <vector>
using namespace std;
#define ll long long
static vector<ll> tree;
void setTree(int i){
	while(i!=0){
		tree[i/2] +=tree[i];
		i--;
	}
}
void changeVal(int idx,int val){
	while(idx!=0){
		tree[idx]+=val;
		idx/=2;
	}
}
ll getSum(int s,int e){
	ll partSum = 0;
	while(s<=e){
		if(s%2==1){
			partSum+=tree[s];
			s++;
		}
		if(e%2==0){
			partSum+=tree[e];
			e--;
		}
		s/=2;
		e/=2;
	}
	return partSum;
}
void solve(){
	int N,M;
	cin >> N;
	int length=N;
	int treeHeight=0;
	while(length!=0){
		length/=2;
		treeHeight++;
	}
	int treeSize = 1<<(treeHeight+1);
	int leftNodeStartIdx = treeSize/2 -1;
	tree.resize(treeSize+1);
	fill(tree.begin(),tree.end(),0);
	for(int i=leftNodeStartIdx+1;i<=leftNodeStartIdx+N;i++){
		cin >> tree[i];
	}
	setTree(treeSize-1);
	cin >> M;
	for(int i=0;i<M;i++){
		char a;
		int b,c;
		cin >> a >> b >> c;
		if(a=='R'){
			cout << getSum(leftNodeStartIdx+b,leftNodeStartIdx+c) << '\n';
		}else if(a=='U'){
			changeVal(leftNodeStartIdx+b,c);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}