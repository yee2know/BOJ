//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static int N;
int cal(int x,int n){
	int cnt=0;
	if(x<10&&n==0){
		cnt++;
	}
	while(x>0){
		if(x%10==n) cnt++;
		x/=10;
	}
	return cnt;
}

int fromTo(int a,int b,int c,int d){
	int cnt=0;
	for(int i=a;i<c;i++){
		for(int j=((i==a)?b:0);j<60;j++){
			cnt+=(cal(i,N)+cal(j,N))>0;
		}
	}
	for(int i=((a==c)?b:0);i<=d;i++){
		cnt+= (cal(c,N)+cal(i,N))>0;
	}
	return cnt;
}

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c>> d;
	cin >> N;
	cout << fromTo(a,b,c,d);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}