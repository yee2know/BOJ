//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){

    ll n;
    cin >> n;
 
    vector<ll> A;

    ll x = n;
    for (ll i=2;i*i<=n;i++){
        while (x%i==0){
            A.push_back(i);
            x/=i;
        }
    }

    if (x!=1) A.push_back(x);
 
    cout << A.size() << "\n";
    for (ll ele : A) cout << ele << " ";
 
    return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}