#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int i=1;
	while(i*(i+1)/2<=N){
		i++;
	}
	cout << i-1;
	return 0;
}