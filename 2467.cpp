#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin >>A[i];
	int s=0,e=N-1;
	pair<int,int> answer={-1,-1};
	int sum=2000000010;
	for(int i=0;i<N-1;i++){
		if(abs(sum)>abs(A[i]+A[i+1])){
			answer = {A[i],A[i+1]};
			sum = abs(A[i]+A[i+1]);
		}
	}
	while(s<e){
		int tmp = A[s]+A[e];
		if(abs(sum)>abs(tmp)){
			sum = tmp;
			answer = {A[s],A[e]};
		}
		if(tmp>0) e--;
		else s++;
	}
	cout << answer.first << " " << answer.second;
	return 0;
}