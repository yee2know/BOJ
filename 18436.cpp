#include <vector>
#include <iostream>
using namespace std;
static vector<int> tree;
void setTree(int i){
	while(i!=1){
		tree[i/2]+=tree[i];
		i--;
	}
}

void changeVal(int idx,int val){
	val%=2;
	int diff = val-tree[idx];

	while(idx>0){
		tree[idx] = tree[idx]+diff;
		idx/=2;
	}
}

int getSum(int s,int e){
	int partSum=0;
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
	int N;
	cin >> N;
	int length =N;
	int treeHeight=0;
	while(length!=0){
		length/=2;
		treeHeight++;
	}                
	int treeSize = 1<<(treeHeight+1);
	int leftNodeStartIndex = treeSize/2 -1;
	tree.resize(treeSize+1);
	for(int i=leftNodeStartIndex+1;i<=leftNodeStartIndex+N;i++){
		cin >> tree[i];
		tree[i] = tree[i]%2;
	}
	setTree(treeSize-1);
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			changeVal(leftNodeStartIndex+b,c);
		}else if(a==3){
			cout << getSum(b+leftNodeStartIndex,c+leftNodeStartIndex) << '\n';
		}else if(a==2){
			cout << c-b+1-getSum(b+leftNodeStartIndex,c+leftNodeStartIndex) << '\n';
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