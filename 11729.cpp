#include <vector>
#include <iostream>
using namespace std;

void hanoi(int N,int from,int tmp,int to){
	if(N==1){
		cout << from << ' ' << to << '\n';
		return;
	}
	hanoi(N-1,from,to,tmp);
	cout << from << ' ' << to << '\n';
	hanoi(N-1,tmp,from,to);
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	cout << (1<<N)-1 << "\n";
	hanoi(N,1,2,3);
	return 0;
}