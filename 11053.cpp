//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int bSearch(vector<int> A,int s,int e,int ele){
	while(s<e){
		int mid = (s+e)/2;
		if(ele>A[mid]) s=mid+1;
		else e = mid;
	}
	return e;
}

void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	vector<int> lis;
	lis.push_back(A[0]);
	int now=0;
	for(int i=1;i<N;i++){
		if(lis[now]<A[i]){
			lis.push_back(A[i]);
			now++;
		}else{
			int pos = bSearch(lis,0,now,A[i]);
			lis[pos] = A[i];
		}
	}
	cout << now+1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}