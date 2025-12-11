//DGUPC용 템플릿 - 출처 원종호 내가 적음
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

const ll INF = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    int s, t;
    cin >> s >> t;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n + 1, INF);
    
    dist[s] = 0;
    pq.push({0, s});
    
    while(!pq.empty()){
        ll d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < d) continue;
        if(cur == t) break;
        
        for(auto& edge : adj[cur]){
            int weight = edge.first;
            int nxt = edge.second;
            
            if(dist[cur] + weight < dist[nxt]){
                dist[nxt] = dist[cur] + weight;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    
    cout << dist[t];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}