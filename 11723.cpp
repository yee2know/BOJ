//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
static vector<bool> A;
void Add(int x){
	A[x]=true;
}
void Remove(int x){
	A[x]=false;
}
int Check(int x){
	return A[x];
}
void Toggle(int x){
	A[x] = !A[x];
}
void All(){
	for(int i=1;i<=20;i++){
		A[i]= true;
	}
}
void Empty(){
	for(int i=1;i<=20;i++){
		A[i]= false;
	}
}
void solve(){
	int N;
	cin >> N;
	A.assign(21,false);
	for(int i=0;i<N;i++){
		string s;
		int x;
		cin >> s;
		if(s=="add"){
			cin >> x;
			Add(x);
		}else if(s=="remove"){
			cin >> x;
			Remove(x);
		}else if(s=="check"){
			cin >> x;
			cout << Check(x) << "\n";
		}else if(s=="toggle"){
			cin >> x;
			Toggle(x);
		}else if(s=="all") All();
		else Empty();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}