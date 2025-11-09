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

bool contained(Point A,Point B, Point C){
	return (min(A.x,B.x)<=C.x&&max(A.x,B.x)>=C.x&&min(A.y,B.y)<=C.y&&max(A.y,B.y)>=C.y);
}

void solve(){
	Point A,B,C,D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	ll a = cal(A,B,C);
	ll b = cal(A,B,D);
	ll c = cal(C,D,A);
	ll d = cal(C,D,B);
	if(a!=b&&c!=d) cout << 1;
	else if(a==0&&a==b&&b==c&&c==d&&(contained(A,B,C)||contained(A,B,D)||contained(C,D,A)||contained(C,D,B))) cout << 1;
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