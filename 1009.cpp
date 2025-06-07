#include <iostream>
using namespace std;
void bun(int a,int b){
	int result=1;
	for(int i=0;i<b;i++){
		result *= a;
		result %= 10;
	}
	if(result%10==0) result=10;
	else result%=10;
	printf("%d\n",result);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,n;
	cin >> n;
	while(n--){
		cin >> a >> b;
		bun(a,b);
	}
	return 0;
}