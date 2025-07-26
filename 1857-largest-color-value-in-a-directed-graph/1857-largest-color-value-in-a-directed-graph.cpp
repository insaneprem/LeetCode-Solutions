class Solution {
public:
    bool isCyclePresent(int node, vector<vector<int>>& adj,
                        vector<int>& visited) {
        visited[node] = 1;

        for (auto e : adj[node]) {
            if (visited[e] == 1)
                return true;
            else if (visited[e] == 0) {
                if (isCyclePresent(e, adj, visited))
                    return true;
            }
        }

        visited[node] = 2;
        return false;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,
             vector<vector<int>>& val, string& color) {
        visited[node] = 1;

        for (auto e : adj[node]) {
            if (visited[e] == 0) {
                dfs(e, adj, visited, val, color);
            }
            for (int i = 0; i < 26; i++) {
                val[node][i] = max(val[e][i], val[node][i]);
            }
        }

        val[node][color[node] - 'a']++;
        visited[node] = 2;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);

        for (auto e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back(v);
        }

        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isCyclePresent(i, adj, visited))
                    return -1;
            }
        }

        vector<vector<int>> val(n, vector<int>(26, 0));
        visited.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, val, colors);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++)
                ans = max(ans, val[i][j]);
        }

        return ans;
    }
};