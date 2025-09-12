#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i =1;
	int N;
	cin >> N;
	int sum=0;
	while(sum+i<=N-1){
		sum+=i++;
	}
	int diff = ((N)-i*(i-1)/2);
	if (i%2==0) cout << diff << "/" << i-diff+1;
	else cout  << i-diff+1<< "/"<< diff;
	return 0;
}