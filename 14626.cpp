#include <vector>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int sum=0;
  int ind;
  for(int i=0;i<13;i++){
	if(s[i]!='*'){
		if(i%2==1) sum+= (s[i]-'0')*3;
		else sum += s[i]-'0';
	}else{
		ind=i;
	}
  }
  int result;
  if(ind%2==1){
	for(int i=0;i<10;i++){
		if((i*3)%10==10-sum%10) {
			result =i;
			break;
		}
	}
  }else{
	result = 10-sum%10;
  }
  if(result==10) result=0;
  cout << result;
  return 0;
}
// 3 6 9 2 5 8 1 4 7 