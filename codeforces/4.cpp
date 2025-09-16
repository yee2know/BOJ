#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int odd=0,even=0;
        bool turn=false;
        long long result=0;
        priority_queue<int,vector<int>,less<int>> oddPQ;
        priority_queue<int,vector<int>,less<int>> evenPQ;
        for(int i=0;i<N;i++){
            int a;
            cin >> a;
            if(a%2==0){
                even++;
                evenPQ.push(a);
            }else{
                odd++;
                oddPQ.push(a);
            }
        }
        if(!oddPQ.empty()){
            while(!evenPQ.empty()){
                result+=evenPQ.top();
                evenPQ.pop();
            }
        }
        for(int i=0;i<(odd+1)/2;i++){
            result+=oddPQ.top();
            oddPQ.pop();
        }
        cout << result << "\n";
    }
	return 0;
}