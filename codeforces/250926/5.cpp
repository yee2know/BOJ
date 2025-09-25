#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
    cin >> t;
    while(t--){
        int N,K,L,R;
        cin >> N >> K >> L >> R;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin >> A[i];
        long long count = 0;
        int r1=0,r2=0;
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;

        for(int i=0;i<N;i++){
            while(r1<N&&freq1.size()<K){
                freq1[A[r1]]++;
                r1++;
            }

            if(freq1.size()<K) break;

            while(r2<N){
                if (freq2.find(A[r2]) == freq2.end() && freq2.size() == K) {
                break;
            }
            freq2[A[r2]]++;
            r2++;
            }


            // 1 1 1 1 1 1 1
            //l=2,r=3
            // r2-r1에서 l보다 작은 r1삭제, r보다 큰 r2 삭제
            int start = max(r1-1,i+L-1);
            int end = min(r2-1,i+R-1);
            if(start<=end) count+=(end-start+1);

            freq1[A[i]]--;
            if(freq1[A[i]]==0) freq1.erase(A[i]);
            freq2[A[i]]--;
            if(freq2[A[i]]==0) freq2.erase(A[i]);
        }
        cout << count << "\n";
    }
	return 0;
}