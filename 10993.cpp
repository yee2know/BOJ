//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
char board[1024][2048];


int getHeight(int n) {
    return (1 << n) - 1; // 2^n - 1
}

int getWidth(int n) {
    return 2 * getHeight(n) - 1;
}

void draw(int n, int x, int y) {
    if (n == 1) {
        board[y][x] = '*';
        return;
    }

    int h = getHeight(n);
    int w = getWidth(n);
    int prev_h = getHeight(n - 1);
    int prev_w = getWidth(n - 1);

    if (n % 2 == 1) { 
		//위
        for (int i = 0; i < h; i++) {
            board[y + i][x + w / 2 - i] = '*';
            board[y + i][x + w / 2 + i] = '*';
            
            if (i==h-1) {
                for (int j=0;j<w;j++) {
                    board[y + i][x + j] = '*';
                }
            }
        }
        draw(n - 1, x + (w - prev_w) / 2, y + h / 2);
    } else {
//역
        for (int i=0;i<h;i++) {
            board[y + i][x + i] = '*';
            board[y + i][x + w - 1 - i] = '*'; 

            if (i==0) {
                for (int j=0;j<w;j++) {
                    board[y][x + j] = '*';
                }
            }
        }
        draw(n - 1, x + (w - prev_w) / 2, y + 1);
    }
}
void solve(){
	int N;
    cin >> N;

    int total_h = getHeight(N);
    int total_w = getWidth(N);

    for(int i=0;i<total_h;i++) {
        for(int j=0;j<total_w;j++) {
            board[i][j] = ' ';
        }
    }

    draw(N, 0, 0);

    for(int i=0;i<total_h;i++){
        int last_star_idx = 0;
        for(int j=0;j<total_w;j++){
            if(board[i][j] == '*'){
                last_star_idx = j;
            }
        }
        
        for(int j=0;j<=last_star_idx;j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    solve();
	return 0;
}