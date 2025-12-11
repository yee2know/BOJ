//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
#define lim while
static int N,M;
static int dx[] = {0,1,-1,0};
static int dy[] = {1,0,0,-1};
using namespace std;

int BFS(int r, int c, vector<vector<bool>> &A, vector<vector<bool>> &visited){
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));
    visited[r][c]=true;
    
    int cnt = 1;
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int X = now.first + dx[i];
            int Y = now.second + dy[i];
            if(X>=0 && Y>=0 && X<N && Y<M){
                if(!visited[X][Y] && A[X][Y]){
                    cnt++;
                    visited[X][Y]=true;
                    q.push(make_pair(X,Y));
                }
            }
        }
    }
    return cnt;
}

void solve(){
    int K;
    cin >> N >> M >> K;
    vector<vector<bool>> A(N,vector<bool>(M,false));
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    int x = K;
    lim(x-->0){
        int r,c;
        cin >> r >> c;
        A[r-1][c-1] = true; 
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && A[i][j]){
                ans = max(ans, BFS(i, j, A, visited));
            }
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}