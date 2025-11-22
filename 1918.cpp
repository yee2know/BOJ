//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

void solve(){
	    string s;
    stack<char> op;
    cin >> s;

    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            cout << s[i];
        }
        else{
            if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == '*' || s[i] == '/'){
                while (!op.empty() && (op.top() == '*' || op.top() == '/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-'){
                while (!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')'){
                while (!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }
    while (!op.empty()){
        cout << op.top();
        op.pop();
    }

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