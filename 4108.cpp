#include <vector>
#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		int M,N;
		cin >> M >> N;
		if(M==0&&N==0) return 0;
		vector<vector<char>> A(M,vector<char>(N));	
		vector<vector<int>> B(M+2,vector<int>(N+2,0));		
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin >> A[i][j];
			}
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(A[i][j]=='*'){
					for(int a=0;a<3;a++){
						for(int b=0;b<3;b++){
							B[i+a][j+b]++;
						}
					}
				}
			}
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(A[i][j]=='*') cout << '*';
				else cout << B[i+1][j+1];
			}
			cout << "\n";
		}
	}
	return 0;
}