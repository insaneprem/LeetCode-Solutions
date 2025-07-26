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

        if (size[pu] > size[pv]) {
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
    int kruskal(int n, vector<vector<int>>& edges, int edge_to_add,
                int edge_to_remove) {
        int MstSum = 0;
        DSU dsu(n);
        int edgeCnt = 0;
        if (edge_to_add != -1) {
            MstSum += edges[edge_to_add][2];
            dsu.unionSize(edges[edge_to_add][0], edges[edge_to_add][1]);
            edgeCnt++;
        }

        for (int i = 0; i < edges.size(); i++) {
            vector<int> e = edges[i];
            if (i == edge_to_remove)
                continue;
            int pu = dsu.findpar(e[0]);
            int pv = dsu.findpar(e[1]);

            if (pu == pv)
                continue;

            dsu.unionSize(e[0], e[1]);
            MstSum += e[2];
            edgeCnt++;
        }

        if (edgeCnt != n - 1)
            return INT_MAX;

        return MstSum;
    }
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(begin(edges), end(edges),
             [](auto a, auto b) { return a[2] < b[2]; });

        int MSTWeight = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudo_critical;
        for (int i = 0; i < edges.size(); i++) {
            int removeWeight = kruskal(n, edges, -1, i);
            int addWeight = kruskal(n, edges, i, -1);
            if (removeWeight > MSTWeight)
                critical.push_back(edges[i][3]);
            else if (removeWeight == MSTWeight && addWeight == MSTWeight)
                pseudo_critical.push_back(edges[i][3]);
        }

        return {critical, pseudo_critical};
    }
};