#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int,int>> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i].second >> A[i].first;
	}
	sort(A.begin(),A.end());
	int sel=A[0].first;
	int counter=1;
	for(int i=1;i<N;i++){
		if(sel<=A[i].second){
			sel=A[i].first;
			counter++;
		}
	}
	cout << counter;
	return 0;
}