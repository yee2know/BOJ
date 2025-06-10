#include <iostream>
using namespace std;
int N;
bool isPrime(int n)
{
	for(int i=2;i<=n/2;i++){
		if(n%i==0) return 0;
	}
	return 1;
}

void DFS(int n,int t){
	if(t==N){
		if(isPrime(n)) cout << n << "\n";
	}
	for(int i=0;i<=9;i++){
		if(isPrime(n*10+i)) DFS(n*10+i,t+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	DFS(2,1);
	DFS(3,1);
	DFS(5,1);
	DFS(7,1);
	return 0;
}