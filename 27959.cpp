#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
static ll N,M;

ll mul(ll n,ll a){
    ll num=0;
    if(a>0){
        while(a--){
            num+=n;
        }
    }
    return num;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    cin >> N >> M;
	priority_queue<ll> pq;
	N = mul(100,N);
	pq.push(N);pq.push(M);
	if(pq.top()==M){
		pq.pop();
		if(pq.top()==M) cout << "Yes";
		else cout << "No";
	}else cout << "Yes";
	return 0;
}