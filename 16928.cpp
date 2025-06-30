#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ladder[101]={0};
	int snake[101]={0};
	for(int i=1;i<=100;i++) {
		ladder[i]=i;
		snake[i]=i;
	}
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		ladder[a]=b;
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		snake[a]=b;
	}
	int D[120]={0};
	for(int i=2;i<110;i++) D[i]=999;
	for(int i=1;i<100;i++){
		for(int j=1;j<=6;j++){
			if(i+j<101&&D[snake[ladder[i+j]]]>D[i]+1){
				D[snake[ladder[i+j]]]=D[i]+1;
			}
		}
	}
		for(int i=1;i<100;i++){
		for(int j=1;j<=6;j++){
			if(i+j<101&&D[snake[ladder[i+j]]]>D[i]+1){
				D[snake[ladder[i+j]]]=D[i]+1;
			}
		}
	}
	cout << D[100];
	return 0;
}