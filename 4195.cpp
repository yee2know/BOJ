#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
static unordered_map<string,string> A;
static unordered_map<string,int> num;
string Find(string s){
	if(s==A[s]) return s;
	else {
		return A[s]=Find(A[s]);
	}
}

void Union(string a, string b){
	a = Find(a);
	b = Find(b);

	if(a!=b){
		A[b]=a;
		num[a]+=num[b];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		A.clear();
		num.clear();
		int N;
		cin >> N;
		for(int i=0;i<N;i++){
			string a,b;
			cin >> a >> b;
			if(A.find(a)==A.end()){
				A[a]=a;
				num[a]=1;
			}
			if(A.find(b)==A.end()){
				A[b]=b;
				num[b]=1;
			}
			Union(a,b);
			cout << num[Find(a)] << "\n";
		}
	}
	return 0;
}