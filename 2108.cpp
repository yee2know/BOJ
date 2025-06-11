#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
	int sum=0;
	vector<int> B(8001);
	for(int i=0;i<N;i++){
		sum+=A[i];
		B[A[i]+4000]++;
	}
	int avg = round(sum/(double)N);
	if(avg==-0) avg=0;
	cout << avg << "\n";
	int index = (N%2==0)?(N/2)+1:(N+1)/2;
	cout << A[index-1] << "\n";
	vector<int> maxs(500000);
	int maxindex=0;
	maxs[0]=0;
	for(int i=1;i<8001;i++){
		if(B[maxs[0]]<B[i]){
			maxindex=0;
			maxs[0]=i;
		}else if(B[maxs[0]]==B[i]){
			maxindex++;
			maxs[maxindex]=i;
		}
	}
	maxs.resize(maxindex+1);
	int max;
	if(maxindex==0) max = maxs[0]-4000;
	else {
		sort(maxs.begin(),maxs.end());
		max= maxs[1]-4000;
	}
	cout << max << "\n";
	cout << A[N-1]-A[0] << "\n";
	return 0;
}