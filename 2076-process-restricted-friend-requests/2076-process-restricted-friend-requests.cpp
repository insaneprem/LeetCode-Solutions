class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
        for (int i = 0; i <= n; i++)
            rank.push_back(0);
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findpar(parent[node]);
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        DSU dsu(n);

        vector<bool> ans;
        for (auto req : requests) {
            int u = req[0], v = req[1];
            int pu = dsu.findpar(u), pv = dsu.findpar(v);

            if (pu == pv) {
                ans.push_back(true);
                continue;
            }

            bool flag = true;
            for (auto rest : restrictions) {
                int px = dsu.findpar(rest[0]);
                int py = dsu.findpar(rest[1]);

                if ((px == pu && py == pv) || (px == pv && py == pu)) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                dsu.unionRank(u, v);

            ans.push_back((flag) ? true : false);
        }

        return ans;
    }
};