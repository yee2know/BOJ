#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string p;
		int n;
		string arr;
		cin >> p >> n >> arr;
		deque<int> A;
		arr.erase(0,1);
		arr.pop_back();
		istringstream iss(arr);
    	string token;
    	while (getline(iss, token, ',')) {
        A.push_front(stoi(token));
    	}
		bool rev=false;
		bool iserror=false;
		for(int i=0;i<p.size();i++){
			if(p[i]=='R'){
				rev = !rev;
			}else if(p[i]=='D'){
				if(A.empty()){
					i=p.size();
					cout << "error\n";
					iserror=true;
					break;
				}else if(!rev){
					A.pop_front();
				}else{
					A.pop_back();
				}
			}
		}
		if(iserror) continue;
		cout << "[";
		if(!rev){
			for(int i=0;i<A.size();i++){
				cout << A.front()<<",";
				A.pop_front();
			}
		}else{
			for(int i=0;i<A.size();i++){
				cout << A.back()<<",";
				A.pop_back();
			}
		}
		cout << "]\n";
	}
	return 0;
}