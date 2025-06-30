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
	for(int i=0;i<N;i++) cin >> A[i];
	int risingMax=0;
	int counter;
	for(int i=0;i<N;i++){
		int localMax=A[i];
		counter=1;
		for(int j=i+1;j<N;j++){
			if(A[j]>localMax){
				counter++;
				localMax=A[j];
			}
		}
		risingMax = max(risingMax,counter);
	}
	cout << risingMax;
	return 0;
}

