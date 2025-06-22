#include <vector>
#include <iostream>
using namespace std;
static vector<int> A,B;
static int N;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  A.resize(N+1);
  B.resize(N+1);
  int temp;
  for(int i=1;i<=N;i++){
    cin >> temp;
    B[i]=temp;
    A[i]=i;
  }
  int counter=0;
  int max=-1;
  int ind;
  while(max!=0){
    //for(int i=1;i<=N;i++) cout << A[i] << " ";
    //cout << "\n";
    for(int i=1;i<=N;i++){
      if(max<abs(i-A[B[i]])){
        max=abs(i-A[B[i]]);
        ind=i;
      }
    }
    //5 1 2 3 4
    //2 0 2 0 0
    //max = 4 ind=5
    counter+=max;
    if(ind-A[B[ind]]>0){
      //ind=5 A[B[ind]]=1
      for(int i=1;i<=N;i++){
        if(A[i]>A[B[ind]]&&A[i]<=ind) A[i]--;
      }
    }else{
      //ind =1 A[B[ind]] = 3
      for(int i=1;i<=N;i++){
        if(A[i]>=ind&&A[i]<A[B[ind]]) A[i]++;
      }
    }
    A[B[ind]]=ind;
    max=0;
    for(int i=1;i<=N;i++){
      max+=abs(i-A[B[i]]);
    }
    if(max==0) break;
    else max=-1;
  }
  cout << counter;
  return 0;
}