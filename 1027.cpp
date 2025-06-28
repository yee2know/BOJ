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
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	int max=0;
	for(int i=0;i<N;i++){
		int counter=0;
		int l=i-1,r=i+1;
		int lm=0,rm=0;
		while(l>=0&&lm<A[l]){
			lm=A[l];
			counter++;
			l--;
		}
		while(r<=N-1&&rm<A[r]){
			counter++;
			rm = A[r];
			r++;
		}
		if(max<counter) max = counter;
	}
	cout << max;
	return 0;
}