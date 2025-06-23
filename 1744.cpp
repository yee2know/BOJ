#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  priority_queue<int> pluspq;
  priority_queue<int, vector<int>,greater<int>> minuspq;
  int one=0,zero=0;
  int temp;
  for(int i=0;i<N;i++){
	cin >> temp;
	if(temp>1) pluspq.push(temp);
	else if(temp<0) minuspq.push(temp);
	else if(temp==0) zero++;
	else if(temp==1) one++;
  }
  int sum=0;
  while(pluspq.size()>1){

		temp=pluspq.top();
		pluspq.pop();
		sum+= pluspq.top()*temp;
		pluspq.pop();
	}
	if(!pluspq.empty()){
		sum+=pluspq.top();
		pluspq.pop();
	}
  while(minuspq.size()>1){
		temp=minuspq.top();
		minuspq.pop();
		sum+= minuspq.top()*temp;
		minuspq.pop();
  }
  if(!minuspq.empty()){
	if(zero==0){
		sum+=minuspq.top();
		minuspq.pop();
	}
  }
  sum+=one;
  cout << sum;
  return 0;
}