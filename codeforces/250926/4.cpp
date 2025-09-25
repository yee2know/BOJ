#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        int aba=0,bab=0,ab=0,ba=0;
        //aba
        stack<int> b;
        for(int i=0;i<N/2;i++){
            if(S[i]=='b') b.push(i);
            else if(S[i]=='a'&&!b.empty()){
                int diff = i-b.top();
                S[b.top()]='a';
                S[i]='b';
                b.pop();
                aba+=diff;
            }
        }
    }
	return 0;
}