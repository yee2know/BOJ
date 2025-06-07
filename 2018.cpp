#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,start_index=1,end_index=1,sum=1,count=1;
	cin >> n;
	while(end_index!=n){
		if(sum==n){
			count++;
			end_index++;
			sum+=end_index;
		}else if(sum>n){
			sum-=start_index;
			start_index++;
		}else if(sum<n){
			end_index++;
			sum+=end_index;
		}
	}
	cout << count;
	return 0;
}