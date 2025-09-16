#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
    int N,M,X,Y;
    cin >> T;
    while(T--){ 
        cin >> N >> M >> X >> Y;
        vector<int> A(N);
        vector<int> B(M);
        for(int i=0;i<N;i++) cin >> A[i];
        for(int i=0;i<M;i++) cin >> B[i];
        cout << N+M << "\n";
    }
	return 0;
}