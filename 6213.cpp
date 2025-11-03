#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

static vector<long long> tree1; //min
static vector<long long> tree2; //max
long long getMin(int s,int e);
long long getMax(int s,int e);

void solve(){
	int N,M;
	cin >> N >> M;
	int length=N,treeHeight=0;
	while(length!=0){
		treeHeight++;
		length/=2;
	}
	int treeSize = int(pow(2,treeHeight+1));
	int leftStartIdx = treeSize/2 -1;
	tree1.resize(treeSize+1);
	tree2.resize(treeSize+1);
	for(int i = 1;i<=N;i++){
		cin >> tree1[i+leftStartIdx];
		tree2[i+leftStartIdx]=tree1[i+leftStartIdx];;
	}
	for(int i=leftStartIdx;i>0;i--){
		tree1[i]=min(tree1[i*2],tree1[i*2+1]);
		tree2[i]=max(tree2[i*2],tree2[i*2+1]);
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		cout << getMax(a+leftStartIdx,b+leftStartIdx) - getMin(a+leftStartIdx,b+leftStartIdx) << "\n";
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

long long getMin(int s,int e){
	long long partMin = 1000001000;
	while(s<=e){
	if(s%2==1){
		partMin = min(partMin,tree1[s]);
		s++;
	}
	if(e%2==0){
		partMin = min(partMin,tree1[e]);
		e--;
	}
	s/=2;
	e/=2;
}
	return partMin;
}

long long getMax(int s,int e){
	long long partMax = 0;
	while(s<=e){
	if(s%2==1){
		partMax = max(partMax,tree2[s]);
		s++;
	}
	if(e%2==0){
		partMax = max(partMax,tree2[e]);
		e--;
	}
	s/=2;
	e/=2;
}
	return partMax;
}