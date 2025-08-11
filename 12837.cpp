#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

static vector<long long> tree;
long long getSum(int s,int e);
void changeVal(int ind,long val);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,K;
	cin >> N >> K;
	int treeHeight=0,length=N;
	while(length!=0){
		length/=2;
		treeHeight++;
	}
	int treeSize = int(pow(2,treeHeight+1));
	int leftStartInd = treeSize/2-1;

	tree.resize(treeSize+1);
	for(int i=1;i<=treeSize-1;i++){
		tree[i]=0;
	}
	//tree 초기화
	int p =treeSize-1;
	while(p!=1){
		tree[p/2]+=tree[p];
		p--;
	}
	for(int i=0;i<K;i++){
		long a,s,e;
		cin >> a >> s >> e;
		if(a==1){
			changeVal(s+leftStartInd,e);
		}else if(a==2){
			s+=leftStartInd;
			e+=leftStartInd;
			cout << getSum(s,e) << "\n";
		}
	}
	return 0;
}

long long getSum(int s,int e){
	long partSum=0;

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
void changeVal(int ind,long val){
	while(ind>0){
		tree[ind]+=val;
		ind/=2;
	}
}