#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

static vector<long long> tree;
char getSum(int s,int e);
void changeVal(int ind,long long val);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1){
	int N,K;
	cin >> N;
	if(cin.eof()) break;
	cin >> K;
	int treeHeight=0,length=N;
	while(length!=0){
		length/=2;
		treeHeight++;
	}
	int treeSize = int(pow(2,treeHeight+1));
	int leftStartInd = treeSize/2-1;

	tree.resize(treeSize+1);
    for(int i=0;i<=treeSize-1;i++) tree[i]=1;
	for(int i=leftStartInd+1;i<=leftStartInd+N;i++){
		int a;
		cin >> a;
		if(a>0) tree[i]=1;
		else if(a<0) tree[i]=-1;
		else tree[i]=0;
	}
	//tree 초기화
	int p =treeSize-1;
	while(p!=1){
		int a = tree[p/2]*tree[p];
		if(a>0) tree[p/2]=1;
		else if(a<0) tree[p/2]=-1;
		else tree[p/2]=0;
		p--;
	}
	for(int i=0;i<K;i++){
		long s,e;
		char a;
		cin >> a >> s >> e;
		if(a=='C'){
			long long v = (e > 0 ? 1 : (e < 0 ? -1 : 0));
			changeVal(s+leftStartInd,v);
		}else if(a=='P'){
			s+=leftStartInd;
			e+=leftStartInd;
			cout << getSum(s,e);
		}
	}
	cout << "\n";
}
	return 0;
}

char getSum(int s,int e){
	long long partSum=1;

	while(s<=e){
		if(s%2==1){
			partSum*=tree[s];
			s++;
		}
		if(e%2==0){
			partSum*=tree[e];
			e--;
		}
		s/=2;
		e/=2;
	}
	if(partSum>0) return '+';
	else if(partSum<0) return '-';
	return '0';
}
void changeVal(int ind,long long val){
    tree[ind]=val;
    ind/=2;
	while(ind>0){
		tree[ind]=tree[ind*2]*tree[ind*2+1];
		ind/=2;
	}
}