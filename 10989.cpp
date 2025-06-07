#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,temp;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> temp;
		a[temp]++;
	}
	for(int i=0;i<10001;i++){
		for(int j=0;j<a[i];j++){
			cout << i << "\n";
		}
	}
	return 0;
}