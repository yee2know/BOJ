#include <vector>
#include <iostream>
using namespace std;
static bool paint[3072][8000];
static int N;
void draw(int x,int y){
	paint[y][x]=true;
	paint[y+1][x+1]=paint[y+1][x-1]=true;
	for(int i=0;i<5;i++) paint[y+2][x+i-2]=true;
}

void bigdraw(int x,int y,int n){
	if(n==3) {
		draw(x,y);
		return;
	}
	else if(n<3) return;
	bigdraw(x,y,n/2);
	bigdraw(x+n/2,y+n/2,n/2);
	bigdraw(x-n/2,y+n/2,n/2);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	bigdraw(N-1,0,N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N*2-1;j++){
			if(paint[i][j]) cout << '*';
			else if(paint[i][j]==false) cout << ' ';
		}
		cout << "\n";
	}
	return 0;
}