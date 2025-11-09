//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define ld long double
using namespace std;

typedef struct{
	ll x;
	ll y;
} Point;

typedef struct{
	ld x;
	ld y;
} dPoint;

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

dPoint calStraight(Point A,Point B,Point C,Point D){
    ld a1 = (ld)B.y - A.y;
    ld b1 = (ld)A.x - B.x;
    ld c1 = (ld)B.x * A.y - A.x * B.y;

    ld a2 = (ld)D.y - C.y;
    ld b2 = (ld)C.x - D.x;
    ld c2 = (ld)D.x * C.y - C.x * D.y;

    ld fuck = a1 * b2 - a2 * b1;

    dPoint result;
    result.x = (b1 * c2 - b2 * c1) / fuck;
    result.y = (a2 * c1 - a1 * c2) / fuck;
	return result;
}

bool same(Point A,Point B) {return ((A.x==B.x)&&(A.y==B.y));}
bool onlyOnePoint(Point A,Point B,Point C,Point D){
	if(
		(same(A,C)&&!contained(A,B,D)&&!contained(C,D,B))
		||
		(same(A,D)&&!contained(A,B,C)&&!contained(C,D,B))
		||
		(same(B,C)&&!contained(A,B,D)&&!contained(C,D,A))
		||
		(same(B,D)&&!contained(A,B,C)&&!contained(C,D,A))
	){
		return true;
	}
	return false;
}
void solve(){
	Point A,B,C,D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	ll a = cal(A,B,C);
	ll b = cal(A,B,D);
	ll c = cal(C,D,A);
	ll d = cal(C,D,B);
	if(a!=b&&c!=d) {
		cout << 1 << "\n";
		cout<<fixed;
        cout.precision(10);
		dPoint result = calStraight(A,B,C,D);
		cout << result.x << " " << result.y;
	}else if(onlyOnePoint(A,B,C,D)){
		cout << 1 << "\n";
		if(same(A,C)) cout << A.x << " " << A.y;
		else if(same(A,D)) cout << A.x << " " << A.y;
		else if(same(B,C)) cout << B.x << " " << B.y;
		else if(same(B,D)) cout << B.x << " " << B.y;
	}
	else if(a==0&&a==b&&b==c&&c==d&&(contained(A,B,C)||contained(A,B,D)||contained(C,D,A)||contained(C,D,B))) 
		cout << 1;

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