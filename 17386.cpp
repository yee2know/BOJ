//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

typedef struct{
	ll x;
	ll y;
} Point;

ll cal(Point A,Point B,Point C){
	ll a = B.x - A.x;
	ll b = B.y - A.y;
	ll c = C.x - B.x;
	ll d = C.y - B.y;
	ll result = a*d-b*c;
	if(result>0) return 1;
	else if(result==0) return 0;
	else return -1;
}

void solve(){
	Point A,B,C,D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	if(cal(A,B,C)!=cal(A,B,D)&&cal(C,D,A)!=cal(C,D,B)) cout << 1;
	
	else cout << 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}