#include <bits/stdc++.h>
using namespace std;

class Prim {
public:
    int mst(int n, vector<vector<pair<int, int>>>& adj) {
        vector<bool> inMST(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int mstCost = 0;
        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;
            mstCost += w;
            for (auto& [v, weight] : adj[u]) {
                if (!inMST[v]) pq.push({weight, v});
            }
        }
        return mstCost;
    }
};

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0] = {{1, 4}, {2, 1}};
    adj[1] = {{0, 4}, {2, 2}, {3, 1}};
    adj[2] = {{0, 1}, {1, 2}, {3, 5}};
    adj[3] = {{1, 1}, {2, 5}, {4, 3}};
    adj[4] = {{3, 3}};
    Prim p;
    cout << "Prim MST cost: " << p.mst(n, adj) << "\n";
    return 0;
}
