#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> butter;
static int N;
static vector<butter> A;
bool isPossible(int height){
	vector<butter> q(N);
	for(int i=0;i<N;i++){
		butter a = A[i];
		int time;
		if(a.first<height){
			time = (a.first-1)/2;
		}else{
			time = (height-1)/2;
		}
		q[i] = {a.second-time,a.second+time};
	}
	sort(q.begin(),q.end());
	int last = -1900000000;
	for(int i=0;i<N;i++){
		butter now = q[i];
		if(last>=now.first) {
			return false;
		}
		last = now.second;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	A.resize(N);
	int maxHeight=0;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		if(maxHeight<b) maxHeight=b;
		A[i]= {b,a};
	}
	if(maxHeight==1){
		cout << "forever";
		return 0;
	}
	int height = 0;
	int low = 0,high = maxHeight;
	while(low+1<high){
		int mid = ((low+high)/2);
		if(isPossible(mid+1)) {
			low = mid;
			height = max(mid+1,height);
		}
		else high = mid;
	}
	if(maxHeight<=height){
		cout << "forever";
		return 0;
	}
	if(height%2==0) height--;
	cout << height/2;
	return 0;
}