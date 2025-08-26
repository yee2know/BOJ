#include <queue>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
bool isSub(string base,string sub){
	int j=0;
	for(int i=0;i<base.size()&&j<sub.size();i++){
		if(base[i]==sub[j]){
			j++;
		}
	}
	return j==sub.size();
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; string S;	
	cin >> N >> S;
	string answer=S;
	typedef pair<int,string> word;
	priority_queue<word> pq;
	vector<vector<string>> A(81);
	for(int i=0;i<N;i++){
		string tmp;
		cin >> tmp;
		A[tmp.size()].push_back(tmp);
	}
	pq.push({3,S});
	while(!pq.empty()){
		word now = pq.top();
		pq.pop();
		for(string next : A[now.first+1]){
			if(isSub(next,now.second)){
				answer=next;
				pq.push({now.first+1,next});
			}
		}
	}
	cout <<answer;
	return 0;
}