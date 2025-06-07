#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

    int N, L;
    cin >> N >> L;

    vector<pair<int,int>> win;
    win.reserve(L);
    int front = 0, back = 0;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;

        while (back > front && win[back - 1].first > temp) {
            win.pop_back();
            back--;
        }
        win.emplace_back(temp, i);
        back++;

        if (win[front].second <= i - L) {
            front++;
        }
        cout << win[front].first << " ";
    }
    return 0;
}
// 1,1
// 1,1 2,3
// 1,1 3,2
// 3,2 4,4
// 3,2 4,4 5,5
// 4,4 5,5 6,6
// 5,5 6,6 7,7