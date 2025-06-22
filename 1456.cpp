#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    long long A, B;
    cin >> A >> B;

    const int MAX = 10000000;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;


    for (int i = 2; i * 1LL * i <= MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }

    int count = 0;

    for (int i = 2; i <= MAX; ++i) {
        if (!isPrime[i]) continue;

        long long val = (long long)i * i;
        while (val <= B) {
            if (val >= A) count++;
            if (val > B / i) break;
            val *= i;
        }
    }

    cout << count << '\n';
    return 0;
}