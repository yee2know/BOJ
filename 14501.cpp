#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

static vector<int> D,T,P;
static int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	D.resize(N+1);
	P.resize(N+1);
	T.resize(N+1);
	for(int i=0;i<N;i++){
		cin >> T[i] >> P[i];
	}
	D[N]=0;
	for(int i=N-1;i>=0;i--){
		if(i+T[i]>N)
			D[i]=D[i+1];
		else{
			D[i]= max(D[i+1],D[i+T[i]]+P[i]);
		}
	}
	cout << D[0];
	return 0;
}