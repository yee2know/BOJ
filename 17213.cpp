#include <vector>
#include <iostream>
using namespace std;

int C(int a,int b){
	long long num=1;
	for(int i=0;i<b;i++){
		num *= a-i;
	}
	for(int i=2;i<=b;i++){
		num/=i;
	}
	return num;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	cout << C(M-1,N-1);
	return 0;
}

// 