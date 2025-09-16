#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        int prev=-1;
        int prev1;
        int a,b;
        int count=0;
        for(int i=0;i<N;i++){
            cin >> a >> b;
            if(prev==-1){
                if(a%2==b%2){
                    count+=a;
                }else{
                    count+=(a-1);
                }
            }else if((prev1==b&&(a-prev)%2==0)||prev1!=b&&(a-prev)%2==1){
                count += (a-prev);
            }else{
                count += (a-prev-1);
            }
            prev=a;
            prev1=b;
        }
        if(prev==M)
        cout << count << "\n";
        else{
            cout << count+M-prev << "\n";
        }
    }
	return 0;
}