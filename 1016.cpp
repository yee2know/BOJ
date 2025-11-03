#include <vector>
#include <iostream>
using namespace std;

#define ll long long

void solve(){
  ll min,max;
  cin >> min >> max;
  ll midx = max-min+1;
  vector<ll> A(midx);
  for(int i=0;i<midx;i++){
    A[i] = min+i;
  }
  int D[1100000];
  for(int i=0;i<1100000;i++) D[i] = i;
  for(ll i=2;i<1100000;i++){
    if(D[i]==0) continue;
    
    ll minN = i*i;
    
    if(minN>max) break;
    
    ll s = (min/minN)*minN;
    if(s<min) {
      s+=minN;
    }

    ll idx = s-min;
    for(ll j=idx;j<midx;j+=minN) A[j]=0;

    for(ll j=i+i;j<1100000;j+=i){
      D[j]=0;
    }
  }
  
  ll result=0;
    for(int i=0;i<midx;i++){
    if(A[i]!=0) result++;
  }
  cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}