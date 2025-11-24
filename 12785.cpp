#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

#define MOD 1000007

ll C[500][500];

void precomputeCombinations() {
    for (int i=0;i<500;i++) {
        C[i][0] = 1;
        for (int j=1;j<=i;j++) {
            // nCr = n-1Cr-1 + n-1Cr
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}

void solve() {
	precomputeCombinations();
    int w, h;
    int tx, ty;

	cin >> w >> h >> tx >> ty;

    int dx1 = tx - 1;
    int dy1 = ty - 1;
    ll cnt1 = C[dx1 + dy1][dx1];

    int dx2 = w - tx;
    int dy2 = h - ty;
    ll cnt2 = C[dx2 + dy2][dx2];

    cout << (cnt1 * cnt2) % MOD;

	return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}