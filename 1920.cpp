#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >> A[i];
	sort(A.begin(),A.end());
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		int find=false;
		int start=0,end=A.size()-1;
		int temp;
		cin >> temp;
		while(start<=end){
			int mid=(start+end)/2;
			int midV=A[mid];
			if(temp>midV){
				start=mid+1;
			}else if(temp<midV){
				end=mid-1;
			}else{
				find=true;
				break;
			}
		}
		if(find) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}