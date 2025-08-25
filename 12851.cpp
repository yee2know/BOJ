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
	int count=0;
	int time=-99;
	bool isFirst=true;
	while(!q.empty()){
		pos now = q.front();
		q.pop();
		int p = now.first;
		int t = now.second;
		if(isFirst&&p==K){
			time=t;
			count++;
			isFirst=false;
		}
		else if(!isFirst&&p==K&&t==time){
			count++;
		}
		visited[p]=true;
		if(p+1>=0&&p+1<=100000&&!visited[p+1]){
				q.push({p+1,t+1});
		}
		if(p-1>=0&&p-1<=100000&&!visited[p-1]){
				q.push({p-1,t+1});
		}
		if(p*2>=0&&p*2<=100000&&!visited[p*2]){
				q.push({p*2,t+1});
		}
	}
	cout << time << "\n";
	cout <<	count;
	return 0;
}