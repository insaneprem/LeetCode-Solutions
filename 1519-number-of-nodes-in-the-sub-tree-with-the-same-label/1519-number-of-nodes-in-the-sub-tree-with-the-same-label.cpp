class Solution {
public:
    void dfs(int node, int parent, string& label, vector<vector<int>>& freq,
             vector<vector<int>>& adj) {

        freq[node][label[node] - 'a'] = 1;

        for (auto e : adj[node]) {
            if (e == parent)
                continue;
            dfs(e, node, label, freq, adj);

            for (int i = 0; i < 26; i++)
                freq[node][i] += freq[e][i];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        vector<vector<int>> adj(n);

        for (auto e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> freq(n, vector<int>(26, 0));

        dfs(0, -1, labels, freq, adj);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = freq[i][labels[i] - 'a']++;
        }

        return ans;
    }
};