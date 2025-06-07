#include <queue>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	struct compare{
		bool operator()(int o1,int o2){
			int first_abs=abs(o1);
			int second_abs=abs(o2);
			if(first_abs==second_abs){
				return o1>o2;
			}else{
				return first_abs>second_abs;
			}
		}
	};

	priority_queue<int, vector<int>,compare> Myqueue;

	int N;
	cin >> N;

	for(int i=0;i<N;i++){
		int request;
		cin >> request;

		if(request==0){
			if(Myqueue.empty()){
				cout << "0\n";
			}else{
				cout << Myqueue.top() << "\n";
				Myqueue.pop();
			}
		}else{
			Myqueue.push(request);
		}

	}

	return 0;
}