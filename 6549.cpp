#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1500000000
using namespace std;
static vector<int> tree;

void setTree(int i){
	while(i!=1){
		if(tree[i/2]>tree[i]){
			tree[i/2]=tree[i];
		}
		i--;
	}
}

int getMin(int s,int e){
	int Min = MAX;
	while(s<=e){
		if(s%2==1){
			Min = min(Min,tree[s]);
			s++;
		}
		if(e%2==0){
			Min = min(Min,tree[e]);
			e--;
		}
		s/=2;
		e/=2;
	}
	return Min;
}

void solve(){
	int N=-1;
	while(N!=0){
		cin >> N;
		if(N==0) return;
		int length=N;
		int treeHeight=0;
		while(N!=0){
			length/=2;
			treeHeight++;
		}
		int treeSize = 1<<(treeHeight+1);
		int leftNodeStartIdx = treeSize/2 -1;
		tree.resize(treeSize+1);
		fill(tree.begin(),tree.end(),MAX);

		for(int i=leftNodeStartIdx+1;i<=leftNodeStartIdx+N;i++){
			cin >> tree[i];
		}
		setTree(treeSize-1);
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