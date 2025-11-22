//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
typedef pair<double,double> p;


double Get(p a,p b,p c){
	double ans=0;
	ans +=(a.first*b.second+b.first*c.second+c.first*a.second);
	ans -=(b.first*a.second+c.first*b.second+a.first*c.second);
	return ans/2;
}

void solve(){
	int N;
	cin >> N;
	vector<p> A;
	for(int i=0;i<N;i++){
		double a,b;
		cin >> a >> b;
		A.push_back({a,b});
	}
	double ans=0;
	for(int i=1;i<A.size();i++){
		ans += Get(A[0],A[i-1],A[i]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}