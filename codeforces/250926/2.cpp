#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin >> A[i];
        }
        sort(A.begin(),A.end());
        int mini = 0;
        for(int i=0;i<N;i+=2){
            mini = max(mini,abs(A[i]-A[i+1]));
        }
        cout << mini << "\n";
    }
	return 0;
}