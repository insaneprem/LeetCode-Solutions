class Solution {
public:
    int ans = -1;

    void dfs(int node, int d, vector<vector<int>>& adj,
             vector<int>& visited, vector<int>& depth) {
        visited[node] = 1;
        depth[node] = d;

        for (auto e : adj[node]) {
            if (visited[e] == 0) {
                dfs(e, d + 1, adj, visited, depth);
            } else if (visited[e] == 1) {
                ans = max(ans, depth[node] - depth[e] + 1);
            }
        }

        visited[node] = 2;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        vector<int> visited(n, 0), depth(n);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i, 0, adj, visited, depth);
            }
        }

        return ans;
    }
};
