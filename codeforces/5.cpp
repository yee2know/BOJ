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
        int N,K;
        int count=0;
        cin >> N >> K;
        vector<int> A(N);
        vector<int> list;
        vector<int> freq(N+1,0);
        for(int i=0;i<N;i++){
            cin >> A[i];
            freq[A[i]]++;
        }
        bool isOK=true;
        for(int i=0;i<=N;i++){
            if(freq[i]%K!=0){
                isOK=false;
            }
        }
        if(!isOK){
            cout << "0\n";
        }else{
            vector<int> OKlist(N+1,0);
            for(int i=0;i<=N;i++){
                OKlist[i]=freq[i]/K;
            }
            int l=0,r=0;
            
            vector<int> cntList(N+1,0);
            cntList[A[r]]++;
            while(l<=r){
                bool isOver=false;
                for(int i=1;i<=N;i++){
                    if(cntList[i]>OKlist[i]) isOver=true;
                }
                if(!isOver) {
                    if(r<=N){
                    r++;
                    cntList[A[r]]++;
                    }
                    count++;
                }else{
                    cntList[A[l]]--;
                    l++;
                }
            }
            cout << count << "\n";
        }
        
    }
	return 0;
}