#include <bits/stdc++.h>
using namespace std;

class Dijkstra {
public:
    vector<int> run(int n, vector<vector<pair<int, int>>>& adj, int src) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0] = {{1, 4}, {2, 1}};
    adj[1] = {{3, 1}};
    adj[2] = {{1, 2}, {3, 5}};
    adj[3] = {{4, 3}};
    Dijkstra d;
    vector<int> dist = d.run(n, adj, 0);
    for (int i = 0; i < n; i++)
        cout << "Node " << i << ": " << dist[i] << "\n";
    return 0;
}
