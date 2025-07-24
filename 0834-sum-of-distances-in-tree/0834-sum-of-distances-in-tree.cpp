class Solution {
public:
    int subtree[100005];
    int dp[100005];
    int ans[100005];

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        subtree[node] = 1;
        dp[node] = 0;

        for (auto e : adj[node]) {
            if (e == parent)
                continue;
            dfs(e, node, adj);
            subtree[node] += subtree[e];
            dp[node] += dp[e] + subtree[e];
        }
    }

    void rerooting(int node, int parent, int n, vector<vector<int>>& adj) {
        for (auto e : adj[node]) {
            if (e == parent)
                continue;
            dp[e] = dp[node] - subtree[e] + (n - subtree[e]);
            rerooting(e, node, n, adj);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj);
        ans[0] = dp[0];
        rerooting(0, -1, n, adj);

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = dp[i];
        return res;
    }
};
