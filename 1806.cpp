#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int start = 0, end = 0, sum = 0, minLen = INT_MAX;

    while (true) {
        if (sum >= S) {
            minLen = min(minLen, end - start);
            sum -= A[start++];
        } else if (end == N) break;
        else sum += A[end++];
    }

    cout << (minLen == INT_MAX ? 0 : minLen) << "\n";
    return 0;
}