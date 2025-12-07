//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
    int M;
    cin >> M;

    int len = 1;
    while (true) {
        
        int k = (len - 1) / 2;
        ll count = (1LL << k);

        if (M <= count) {
            ll idx = M - 1;

            ll val = (1LL << k) | idx;
            
            ll ans = 0;
            ll suffix = 0;

            if (len % 2 == 1) {
                
                ll temp = val >> 1;
                int suffix_len = k;
                

                for(int i = 0; i < suffix_len; i++) {
                    if((temp >> i) & 1) {
                        suffix |= (1LL << (suffix_len - 1 - i));
                    }
                }

                ans = (val << suffix_len) | suffix;

            } else {
                
                ll temp = val;
                int suffix_len = k + 1;
                
                for(int i = 0; i < suffix_len; i++) {
                    if((temp >> i) & 1) {
                        suffix |= (1LL << (suffix_len - 1 - i));
                    }
                }
                ans = (val << suffix_len) | suffix;
            }

            cout << ans << "\n";
            return;
        }

       
        M -= count;
        len++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}