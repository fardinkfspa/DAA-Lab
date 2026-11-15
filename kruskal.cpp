#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
        return true;
    }
};

class KEdge {
public:
    int u, v, w;
    KEdge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    bool operator<(const KEdge& o) const { return w < o.w; }
};

class Kruskal {
public:
    int mst(int n, vector<KEdge>& edges) {
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        int mstCost = 0, edgeCount = 0;
        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mstCost += e.w;
                edgeCount++;
                if (edgeCount == n - 1) break;
            }
        }
        return mstCost;
    }
};

int main() {
    int n = 5;
    vector<KEdge> edges = {
        KEdge(0, 1, 4), KEdge(0, 2, 1), KEdge(2, 1, 2),
        KEdge(1, 3, 1), KEdge(2, 3, 5), KEdge(3, 4, 3)
    };
    Kruskal k;
    cout << "Kruskal MST cost: " << k.mst(n, edges) << "\n";
    return 0;
}
