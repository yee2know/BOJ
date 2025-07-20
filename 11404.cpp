#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;
static int N,M;
static long D[101][101];
#define INF INT_MAX

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) D[i][j]=0;
			else D[i][j]=INF;
		}
	}
	for(int i=0;i<M;i++){
		int s,e,v;
		cin >> s >> e >> v;
		if(D[s][e]>v)
		D[s][e]=v;
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(D[i][j]>D[i][k]+D[k][j])
					D[i][j]=D[i][k]+D[k][j];
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(D[i][j]==INF) cout <<"0 ";
			else cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}