#include <vector>
#include <iostream>
using namespace std;

static int N;
static long D[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> D[i][j];
		}
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(D[i][k]==1&&D[k][j]==1){
					D[i][j]=1;
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}