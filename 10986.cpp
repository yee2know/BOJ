#include <iostream>
using namespace std;
long long a[100001];
long long b[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,d;
	long answer=0,temp;;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> temp;
		a[i]=a[i-1]+temp;
	}
	for(int i=1;i<=n;i++){
		d=a[i]%m;
		if(d==0) answer++;
		b[d]++;
	}
	for(int i=0;i<=m;i++){
		answer+= b[i]*(b[i]-1)/2;
	}
	cout << answer;
	return 0;
}