#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;
#define INF 210000000
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	vector<vector<int>> A(N+1,vector<int>(N+1,INF));
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a][b]=1;
		A[b][a]=1;
	}
	for(int i=0;i<=N;i++) A[i][i]=0;
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(A[i][k]+A[k][j]<A[i][j]){
					A[i][j]=A[i][k]+A[k][j];
				}
			}
		}
	}

	int answer=INF;
	int ind=0;
	for(int i=1;i<=N;i++){
		int sum=0;
		for(int j=1;j<=N;j++){
			sum+= A[i][j];
		}
		if(sum<answer){
			answer=sum;
			ind=i;
		}
	}
	cout << ind;
	return 0;
}