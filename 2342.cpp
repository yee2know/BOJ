#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
#define INF 1000000
static int D[100000][5][5];
int cal(int a,int b){
	if(a==0&&b==0) return 0;
	else if(a==0) return 2;
	else if(a==b) return 1;
	else if((a==1&&b==3)||(a==3&&b==1)||(a==2&&b==4)||(a==4&&b==2)) return 4;
	else return 3;
}
void solve(){
	int a=-1;
	vector<int> A;
	while(a!=0){
		cin >> a;
		if(a!=0) A.push_back(a);
	}
	fill(&D[0][0][0],&D[0][0][0]+(25*A.size()),INF);
	D[0][A[0]][0] = D[0][0][A[0]] = 2;
	for(int i=0;i<A.size()-1;i++){
		for(int j=0;j<5;j++){
			if(D[i][A[i]][j]==INF) continue;
			D[i+1][A[i+1]][j] = min(D[i+1][A[i+1]][j],D[i][A[i]][j]+cal(A[i],A[i+1]));
			D[i+1][A[i]][A[i+1]] = min(D[i+1][A[i]][A[i+1]],D[i][A[i]][j]+cal(j,A[i+1]));
		}
		for(int j=0;j<5;j++){
			if(D[i][j][A[i]]==INF) continue;
			D[i+1][j][A[i+1]] = min(D[i+1][j][A[i+1]],D[i][j][A[i]]+cal(A[i],A[i+1]));
			D[i+1][A[i+1]][A[i]] = min(D[i+1][A[i+1]][A[i]],D[i][j][A[i]]+cal(j,A[i+1]));
		}
	}
	int minV = INF;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			minV = min(minV,D[A.size()-1][i][j]);
		}
	}
	cout << minV;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}