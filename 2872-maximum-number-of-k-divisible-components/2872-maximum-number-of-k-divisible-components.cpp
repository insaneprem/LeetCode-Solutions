class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<long long>& subtree) {
        for (auto e : adj[node]) {
            if (e == parent)
                continue;

            dfs(e, node, adj, subtree);
            subtree[node] += subtree[e];
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<long long> subtree;
        for (auto i : values)
            subtree.push_back(i);
        dfs(0, -1, adj, subtree);
        
        int ans=0;
        for (auto i : subtree)
            ans+=(i%k == 0);

        return ans;
    }
};