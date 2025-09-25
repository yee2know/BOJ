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
        int n,k;
        cin >> n >> k;
        vector<bool> A(n+1,false);
        int self=0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            if(a==k) self++;
            A[a]=true;
        }
        int B=0;
        for(int i=0;i<k;i++){
            if(!A[i]) B++;
        }
        int count=0;
        count+=self;
        if(B-self>0) count += (B-self);
        cout << count << "\n";
    }
	return 0;
}