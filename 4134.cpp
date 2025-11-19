//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

bool isPrime(ll n) {
    if (n<=1) 
        return false;
    if (n==2)
        return true;
    if (n%2==0) 
        return false;

    ll limit = (long long)sqrt(n);
    for (ll i = 3; i <= limit; i += 2) {
        if (n%i==0)
            return false;
    }

    return true;
}

ll Find(ll n) {
    ll current = n;
    
    if (current <= 2) {
        return 2;
    }

    while (true) {
        if (isPrime(current)) {
            return current;
        }
        current++;
    }
}

void solve(){
	ll N;
	cin >> N;
	cout << Find(N) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--)
    solve();
	return 0;
}