class DSU {
    vector<int> parent, size, rank;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findpar(parent[node]);
    }

    void unionSize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += pu;
        } else {
            parent[pv] = pu;
            size[pu] += pv;
        }
    }

    void unionRank(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv)
            return;

        if (rank[pu] == rank[pv]) {
            rank[pu]++;
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else
            parent[pv] = pu;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (k >= n) return 0;
        int need = n - k;
        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b){ return a[2] < b[2]; });

        DSU dsu(n);
        vector<int> taken;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dsu.findpar(u) != dsu.findpar(v)) {
                dsu.unionRank(u, v);
                taken.push_back(w);
                if ((int)taken.size() == need)
                    break;
            }
        }

        return taken[need - 1];
    }
};
