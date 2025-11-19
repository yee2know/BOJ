//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
//code
void solve(){
    int h1, m1, s1, h2, m2, s2;
    char c;
    
    cin >> h1 >> c >> m1 >> c >> s1;
    cin >> h2 >> c >> m2 >> c >> s2;

    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;

    int diff = t2 - t1;
    if (diff <= 0) diff += 24 * 3600;

    int h = diff / 3600;
    int m = (diff % 3600) / 60;
    int s = diff % 60;

    cout.fill('0');
    cout.width(2);
    cout << h << ":";
    cout.width(2);
    cout << m << ":";
    cout.width(2);
    cout << s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}