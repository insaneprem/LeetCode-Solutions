class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
        for (int i = 0; i <= n; i++)
            size.push_back(1);
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

        if (size[pu] > size[pu]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (dsu.findpar(u) == dsu.findpar(v))
                continue;
            dsu.unionSize(u, v);
        }

        map<int, int> mp;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];

            int pu = dsu.findpar(u);
            int pv = dsu.findpar(v);
            if (pu == pv) {
                if (mp.find(pu) == mp.end())
                    mp[pu] = w;
                else
                    mp[pu] = mp[pu] & w;
            }
        }

        vector<int> res;

        for (auto q : query) {
            int u = q[0], v = q[1];
            int pu = dsu.findpar(u);
            int pv = dsu.findpar(v);

            int val = -1;
            if (pu == pv)
                val = mp[pu];

            res.push_back(val);
        }

        return res;
    }
};