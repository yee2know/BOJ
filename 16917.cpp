#include <vector>
#include <iostream>
using namespace std;

void solve(){
	long long sum = 0;
	int A,B,C,a,b;
	cin >> A >> B >> C >> a >> b;
	if(A+B<C*2){
		sum = A*a+B*b;
	}else{
		int c = min(a,b);
		sum += c*2*C;
		a-=c;
		b-=c;
		if(b>0){
			sum+= min(b*B,b*2*C);
		}else{
			sum+= min(a*A,a*2*C);
		}
	}
	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}