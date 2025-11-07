#include <vector>
#include <iostream>
using namespace std;

int cal(char A,char B){
	int a = A-'A'+1;
	int b = B-'A'+1;
	if(b>=a) return b-a;
	return b-a+26;
}

void solve(){
	string A,B;
	cin >> A >> B;
	cout << "Distances: ";
	for(int i=0;i<A.size();i++){
		 cout << cal(A[i],B[i]) << ' ';
	} cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--) solve();
	return 0;
}