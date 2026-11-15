#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), weight(w_) {}
};

class BellmanFord {
public:
    vector<int> run(int n, vector<Edge>& edges, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (auto& e : edges) {
                if (dist[e.u] != INT_MAX && dist[e.u] + e.weight < dist[e.v])
                    dist[e.v] = dist[e.u] + e.weight;
            }
        }
        for (auto& e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.weight < dist[e.v]) {
                cout << "Negative cycle detected\n";
                return {};
            }
        }
        return dist;
    }
};

int main() {
    int n = 5;
    vector<Edge> edges = {
        Edge(0, 1, 4), Edge(0, 2, 1), Edge(2, 1, 2),
        Edge(1, 3, 1), Edge(2, 3, 5), Edge(3, 4, 3)
    };
    BellmanFord bf;
    vector<int> dist = bf.run(n, edges, 0);
    for (int i = 0; i < n; i++)
        cout << "Node " << i << ": " << dist[i] << "\n";
    return 0;
}
