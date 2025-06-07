#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i,j,count=0;
	long long k;
	cin >> n;
	vector<int> A(n,0);
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A.begin(),A.end());
	for(int o=0;o<n;o++){
		k=A[o];
		i=0; j=n-1;
		while(i<j){
			if(A[i]+A[j]>k) j--;
			else if(A[i]+A[j]<k) i++;
			else if(A[i]+A[j]==k){
				if(i==o){
				i++;
				continue;
				}
				else if(j==o){
				j--;
				continue;
				}
				count++;
				break;
			}
		}
	}
	cout << count;
	return 0;
}