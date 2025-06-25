#include <vector>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int N,K;
		cin >> N >> K;
		vector<int> A(N+1);
		for(int i=1;i<=N;i++) cin >> A[i];
		vector<vector<int>> B(N+1);
		vector<bool> visited(N+1,false);
		int tmp1,tmp2;
		for(int i=0;i<K;i++){
			cin >> tmp1 >> tmp2;
			B[tmp2].push_back(tmp1);
		}
		vector<int> D(N+1,-1);
		int cal=0;
		for(int i=1;i<=N;i++){
				if(B[i].empty()) {
					visited[i]=true;
					D[i]=A[i];
					cal++;
				}
			}
		while(cal!=N){
			for(int i=1;i<=N;i++){
				if(visited[i]) continue;
				int max=-1;
				for(int j=0;j<B[i].size();j++){
					if(D[B[i][j]]==-1){
						max=-1;
						break;
					}else{
						if(max<D[B[i][j]])max=D[B[i][j]];
					}
				}
				if(max!=-1){
					visited[i]=true;
					D[i]=A[i]+max;
					cal++;
				}
			}
		}
		int x;
		cin >> x;
		cout << D[x] << "\n";
	}
  return 0;
}