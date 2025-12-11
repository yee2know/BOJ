//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

ll get_gcd(ll a, ll b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

void solve(){
    string s;
    cin >> s;

    auto dot_pos = s.find('.');
    
    if (dot_pos == string::npos) {
        cout << s << "/1";
        return;
    }

    auto paren_pos = s.find('(');

    if (paren_pos == string::npos) {
        string num_str = "";
        for (char c : s) {
            if (c != '.') num_str += c;
        }
        
        ll up = stoll(num_str);
        ll down = 1;
        for (auto i = 0; i < s.length() - 1 - dot_pos; i++) {
            down *= 10;
        }
        
        ll g = get_gcd(up, down);
        cout << up / g << "/" << down / g;
    } else {
        string all_nums = "";
        string non_rep_nums = "";
        
        for (char c : s) {
            if (isdigit(c)) all_nums += c;
        }
        
        for (auto i = 0; i < paren_pos; i++) {
            if (isdigit(s[i])) non_rep_nums += s[i];
        }
        
        ll full = stoll(all_nums);
        ll non_rep = stoll(non_rep_nums);
        ll up = full - non_rep;
        
        ll nines_cnt = 0;
        for (auto i = paren_pos + 1; i < s.length(); i++) {
            if (isdigit(s[i])) nines_cnt++;
        }
        
        ll zeros_cnt = 0;
        for (auto i = dot_pos + 1; i < paren_pos; i++) {
            zeros_cnt++;
        }
        
        ll down = 0;
        for (int i = 0; i < nines_cnt; i++) down = down * 10 + 9;
        for (int i = 0; i < zeros_cnt; i++) down = down * 10;
        
        ll g = get_gcd(up, down);
        cout << up / g << "/" << down / g;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}