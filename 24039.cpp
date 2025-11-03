#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N;
	cin >> N;
	int D[30000];
	for(int i=0;i<30000;i++){
		D[i] = i;
	}
	vector<int> A;
	for(int i=2;i<30000;i++){
		if(D[i]==0) continue;
		A.push_back(i);
		for(int j = i+i;j<30000;j+=i){
			D[j]=0;
		}
	}
	int a=0;
	int i=0;
	while(a<=N){
		a = A[i]*A[i+1];
		i++;
	}
	cout << a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}