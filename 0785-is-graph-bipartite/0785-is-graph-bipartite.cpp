class Solution {
public:
    bool ans = true;

    void dfs(int node, vector<vector<int>>& adj, vector<int>& color) {
        for (auto e : adj[node]) {
            if (color[e] == -1) {
                color[e] = !color[node];
                dfs(e, adj, color);
            } else if (color[e] == color[node]) {
                ans=false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                dfs(i, adj, color);
            }
        }

        return ans;
    }
};