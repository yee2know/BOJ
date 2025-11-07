#include <vector>
#include <iostream>
using namespace std;
#define ll long long
static vector<ll> A;
static ll N;
ll findone(){
	ll Min = A[0];
	for(ll i=0;i<6;i++){
		Min = min(Min,A[i]);
	}
	return ((N-2)*(N-2)+(N-2)*(N-1)*4)*Min;
}

ll findtwo(){
	vector<pair<ll,ll>> B = {{0,1},{0,3},{0,4},{0,2},
							   {5,1},{5,2},{5,3},{5,4},
							   {1,2},{2,4},{3,4},{1,3}
							};
	ll Min = A[0]+A[1];
	for(ll i=0;i<B.size();i++){
		Min = min(Min,A[B[i].first]+A[B[i].second]);
	}
	return (N-2)*8*Min+4*Min;
}

ll findthree(){
	ll one[] = {0,0,0,0,5,5,5,5};
	ll two[] = {1,2,4,3,1,2,4,3};
	ll thr[] = {2,4,3,1,2,4,3,1};
	ll Min = A[0]+A[1]+A[2];
	for(ll i=0;i<8;i++){
		Min = min(Min,A[one[i]]+A[two[i]]+A[thr[i]]);
	}
	return Min*4;
}

void solve(){
	A.resize(6);
	cin >> N;
	for(int i=0;i<6;i++){
		cin >> A[i];
	}
		if(N==1){
		ll sum = 0;
		ll Min = A[0];
		for(int i=0;i<6;i++){
			sum += A[i];
			Min = max(Min,A[i]);
		}
		cout << sum - Min;
		return;
	}
	cout << findone()+findtwo()+findthree();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}