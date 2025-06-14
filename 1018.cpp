#include <iostream>
#include <vector>
using namespace std;

int check(const vector<string> s, int x, int y){
	int a=0,b=0;
	for(int i=x;i<x+8;i++){
		for(int j=y;j<y+8;j++){
			if(s[i][j]=='W'&&(i+j)%2==0) a++;
			else if(s[i][j]=='B'&&(i+j)%2==1) a++;
			if(s[i][j]=='B'&&(i+j)%2==0) b++;
			else if(s[i][j]=='W'&&(i+j)%2==1) b++;
		}
	}
	return max(a,b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	vector<string> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	int sq=0;
	for(int i=0;i<N-7;i++){
		for(int j=0;j<M-7;j++){
			sq = max(sq,check(A,i,j));
		}
	}
	cout << 64-sq;
	return 0;
}