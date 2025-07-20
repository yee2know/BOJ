#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
vector<pair<int, int>> adj[1005];
#define INF INT_MAX

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m, st, en;
    cin >> n >> m;

    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;

        for (auto next : adj[cur.second]) {
            if (dist[next.second] <= dist[cur.second] + next.first) continue;       
            dist[next.second] = dist[cur.second] + next.first; 
            prev[next.second] = cur.second;   
            pq.push({dist[next.second], next.second});
        }
    }

    cout << dist[en] << "\n";  

    vector<int> path;
    int at = en;
    while (at != st) {
        path.push_back(at);
        at = prev[at];
    }
    path.push_back(at);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";    
    for (int p : path) {           
        cout << p << ' ';
    }
}