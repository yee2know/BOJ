#include <iostream>
using namespace std;
int cmp(string a, string b){
	int 
	size_a=a.size(),
	size_b=b.size();
	int max=0;
	for(int k=0;k<size_b-size_a+1;k++){
		int temp=0;
		for(int i=0;i<size_a;i++){
			if(a[i]==b[i+k]){
				temp++;
			}
		}
		if(max<temp) 
			max=temp;
		
	}
	return size_a-max;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a,b;
	cin >> a >> b;
	cout << cmp(a,b);
	return 0;
}