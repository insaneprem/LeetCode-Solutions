class Solution {
public:
    void dfs(int node, int par, int d, vector<int>& depth,
             vector<vector<int>>& adj) {
        depth[node] = d;

        for (auto e : adj[node]) {
            if (e == par)
                continue;
            dfs(e, node, d + 1, depth, adj);
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);

        for (auto e : edges1) {
            int u = e[0], v = e[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (auto e : edges2) {
            int u = e[0], v = e[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> depth1(n, 0), depth2(m, 0);

        dfs(0, -1, 0, depth1, adj1);

        int maxdist = -1, farnode = -1;
        for (int i = 0; i < n; i++) {
            if (depth1[i] > maxdist) {
                farnode = i;
                maxdist = depth1[i];
            }
        }

        dfs(farnode, -1, 0, depth1, adj1);

        int dia1 = *max_element(begin(depth1), end(depth1));

        dfs(0, -1, 0, depth2, adj2);

        maxdist = -1, farnode = -1;
        for (int i = 0; i < m; i++) {
            if (depth2[i] > maxdist) {
                farnode = i;
                maxdist = depth2[i];
            }
        }

        dfs(farnode, -1, 0, depth2, adj2);

        int dia2 = *max_element(begin(depth2), end(depth2));

        int finaldia = (dia1 + 1) / 2 + 1 + (dia2 + 1) / 2;
        return max({dia1, dia2, finaldia});
    }
};