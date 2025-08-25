#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N+1);
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	vector<vector<bool>> pal(N+1,vector<bool>(N+1,false));
	pal[1][1]=true;
	for(int i=2;i<=N;i++){
		pal[i][i]=true;
		if(A[i-1]==A[i])pal[i-1][i]=true;
	}
	for(int i=N-1;i>=1;i--){
		for(int j=i+1;j<=N;j++){
			if(A[i]==A[j]&&pal[i+1][j-1])pal[i][j]=true;
		}
	}
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++){
		int a,b;
		cin >> a >> b;
		cout << pal[a][b] << "\n";
	}
	return 0;
}