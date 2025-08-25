#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool visited[100001]={false};
	int N,K;
	cin >> N >> K;
	typedef pair<int,int> pos;
	queue<pos> q;
	q.push({N,0});
	visited[N]=true;
	while(!q.empty()){
		pos now = q.front();
		q.pop();
		int p = now.first;
		int t = now.second;
		if(p==K) {cout << t;return 0;}
		if(p*2>=0&&p*2<=100000){
			if(!visited[p*2]){
				visited[p*2]=true;
				q.push({p*2,t});
			}
		}
		if(p-1>=0&&p-1<=100000){
			if(!visited[p-1]){
				visited[p-1]=true;
				q.push({p-1,t+1});
			}
		}
		if(p+1>=0&&p+1<=100000){
			if(!visited[p+1]){
				visited[p+1]=true;
				q.push({p+1,t+1});
			}
		}
	}
	return 0;
}