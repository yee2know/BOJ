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
        int a;
        int minus=0;
        int zero=0;
        int one=0;
        cin >> a;
        while(a--){
            int A;
            cin >> A;
            if(A==-1){
                minus++;
            }else if(A==0) zero++;
            else one++;
        }
        int count=0;
        count+=zero;
        if(minus%2==1) count+=2;
        cout << count << "\n";
    }
	return 0;
}