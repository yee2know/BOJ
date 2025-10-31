#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<vector<double>> A(N,vector<double>(N+1));
	for(double i=0;i<N;i++){
		for(double j=0;j<=N;j++){
			cin >> A[i][j];
		}
	}
	vector<double> Answer(N);
	double degree=N;
	while(degree>1){
		double idx = N-degree;
		int piv = idx;
		for(int i=idx+1;i<N;i++){
			if(fabs(A[i][idx])>fabs(A[piv][idx])) piv=i;
		}
		if(piv!=idx) swap(A[idx],A[piv]);
		for(double i=idx+1;i<N;i++){
			double a = A[idx][idx];
			double b = A[i][idx];
			double astro = b/a;
			for(int j=idx;j<=N;j++){
				A[i][j] -= A[idx][j]*astro;
			}
		}
		degree--;
	}
	for(int i=N-1;i>=0;i--){
		double sum=0;
		for(int j=i+1;j<N;j++) sum+=A[i][j]*Answer[j];
		Answer[i] = round((A[i][N]-sum)/A[i][i]);
	}
	for(int i=0;i<N;i++) cout << ((Answer[i]==-0)?0:Answer[i]) << " ";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}