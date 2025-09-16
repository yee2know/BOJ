#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        vector<long long> freq(N + 1, 0);
        for (int x : A) {
            if (x < 0 || x > N) {
                cout << 0 << "\n";
                continue;
            }
            freq[x]++;
        }

        if (K == 0) {
            cout << 0 << "\n";
            continue;
        }

        {
            bool ok = true;
            for (int i = 0; i <= N; ++i) {
                if (freq[i] % K != 0) { ok = false; break; }
            }
            if (!ok) {
                cout << 0 << "\n";
                continue;
            }
        }

        vector<long long> allow(N + 1, 0);
        for (int i = 0; i <= N; ++i) allow[i] = freq[i] / K;

        long long ans = 0;
        vector<long long> cnt(N + 1, 0);
        int r = 0;

        for (int l = 0; l < N; ++l) {
            while (r < N) {
                int val = A[r];
                if (cnt[val] + 1 > allow[val]) break;
                cnt[val]++; 
                r++;
            }

            ans += (r - l);

            int lv = A[l];
            cnt[lv]--;
        }

        cout << ans << "\n";

    }
    return 0;
}