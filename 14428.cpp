#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// first 값
// second 인덱스
// 여러번 타이핑하기 귀찮으니 typedef
typedef pair<int,int> node;
static vector<node> tree;
void changeVal(int idx,int val);
/**
 * 가장 작은 값의 인덱스 출력
 */
int getMin(int s,int e);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N;

	//tree height 구하기
	int treeHeight=0,length=N;
	while(length!=0){
		treeHeight++;
		length/=2;
	}
	//tree size 구하기
	int treeSize = 1 << (treeHeight+1);
	int leftStartIdx = treeSize/2-1;

	tree.resize(treeSize+1);
	for(int i=leftStartIdx+1;i<=treeSize-1;i++) tree[i].first=1000010000;
	//tree 입력 받기
	for(int i=leftStartIdx+1;i<=leftStartIdx+N;i++){
		cin >> tree[i].first;
		tree[i].second=i-leftStartIdx;
	}
	//값 업데이트
	for(int p=leftStartIdx;p>0;p--){
		tree[p]= min(tree[p*2],tree[p*2+1]);
		// 아니 이거 pair 전부 복사해서 붙여넣기 하네? 앙 개꿀
	}
	cin >> M;
	// M번 쿼리 진행
	for(int i=0;i<M;i++){
		int a,s,e;
		cin >> a >> s >> e;
		if(a==1){
			changeVal(s+leftStartIdx,e);
		}else if(a==2){
			cout << getMin(s+leftStartIdx,e+leftStartIdx) << "\n";
		}
	}
	return 0;
}

void changeVal(int idx,int val){
	tree[idx].first=val;
	idx/=2;
	while(idx>0){
		tree[idx]=min(tree[idx*2],tree[idx*2+1]);
		idx/=2;
	}
}
int getMin(int s,int e){
	node partMin = {1000010000,1};
	while(s<=e){
		if(s%2==1){
			partMin=min(partMin,tree[s]);
			s++;
		}
		if(e%2==0){
			partMin=min(partMin,tree[e]);
			e--;
		}
		s/=2;
		e/=2;
	}
	return partMin.second;
}