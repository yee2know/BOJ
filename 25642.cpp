#include <vector>
#include <iostream>
using namespace std;
void chopstick(int yt,int yj,bool is_yt){
	if(is_yt){
		yj+=yt;
		if(yj>4) {
			cout << "yt";
			return;
		}else{
			chopstick(yt,yj,!is_yt);
		}
	}else{
		yt+=yj;
		if(yt>4) {
			cout << "yj";
			return;
		}else{
			chopstick(yt,yj,!is_yt);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int yt,yj;
	cin >> yt >> yj;
	chopstick(yt,yj,true);
	return 0;
}

