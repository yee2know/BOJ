#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<long long> A,B;
	int N;
	cin >> N;
	int a[4001],b[4001],c[4001],d[4001];
	for(int i=0;i<N;i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A.push_back(a[i]+b[j]);
			B.push_back(c[i]+d[j]);
		}
	}

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	long long answer=0;
	for(int i=0;i<N*N;i++){
		long long tmp = -A[i];

		auto b1 = lower_bound(B.begin(),B.end(),tmp);
		auto b2 = upper_bound(B.begin(),B.end(),tmp);
		if(tmp==*b1) answer += b2-b1;
	}
	cout << answer;
	return 0;
}