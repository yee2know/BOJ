#include <vector>
#include <iostream>
using namespace std;
static vector<int> A;

void Union(int a,int b){
	int prev_a=-1;
	int prev_b=-1;
	while(a!=prev_a){
		prev_a=a;
		a=A[a];
	}
	while(b!=prev_b){
		prev_b=b;
		b=A[b];
	}
	A[b]=a;
}

int Find(int a){
	vector<int> B;
	if(a==A[a]) return a;
	else{
		return A[a]=Find(A[a]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin >> N >> M;
	A.resize(N+1);
	for(int i=0;i<=N;i++)
		A[i]=i;
	while(M--){
		int op,a,b;
		cin >> op >> a >> b;
		if(op==0){
			Union(min(a,b),max(a,b));
		}else if(op==1){
			if(Find(a)==Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}