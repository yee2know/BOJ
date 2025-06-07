#include <iostream>
#include <string>
using namespace std;
string add(string a, string b) {
    int len = max(a.length(), b.length());
    // 앞에 0 채우기
    a = string(len - a.length(), '0') + a;
    b = string(len - b.length(), '0') + b;

    string result(len, '0');
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // 만약 맨 앞에 carry가 남으면 붙여줘야 함
    if (carry) {
        result = '1' + result;
    }

    return result;
}

string fibo(int n) {
	if(n==0) return "0";
    if (n <= 2) return "1";
    string str[3] = {"1", "1", "0"};

    for (int i = 2; i < n; i++) {
        str[i % 3] = add(str[(i + 1) % 3], str[(i + 2) % 3]);
    }

    return str[(n-1)%3]; // n번째는 str[n%3]이 아님! 마지막 두 수 더해야 n번째
}
// 0 1 1 2 3 5 8
// 0 -1 1 -2 3 -5 8 -13
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,tmp;
	string temp;
	cin >> n;
	tmp=n;
	if(n<0) tmp*=-1;
	temp = fibo(tmp);
	if(n<0&&tmp%2==1) temp = "-"+temp;
	cout << temp;
	return 0;
}