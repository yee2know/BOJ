#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand((unsigned int)time(NULL));
  int N;
  int zero=0,one=0;
  cin >> N;
  int temp;
  for(int i=0;i<N;i++){
    cin >> temp;
    if(temp==0) zero++;
    else one++;
  }
  if(rand()%2==1) cout << "F";
  else cout << "S";
  return 0;
}