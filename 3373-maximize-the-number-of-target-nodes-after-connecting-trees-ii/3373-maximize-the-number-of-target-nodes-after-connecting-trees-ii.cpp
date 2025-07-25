class Solution {
public:
    void dfs(int node, int par, vector<vector<int>>& adj,
             vector<vector<int>>& dist) {
        dist[node][0] = 0;
        dist[node][1] = 1;

        for (auto e : adj[node]) {
            if (e == par)
                continue;

            dfs(e, node, adj, dist);
            dist[node][0] += dist[e][1];
            dist[node][1] += dist[e][0];
        }
    }

    void reroot(int node, int par, vector<vector<int>>& adj,
                vector<vector<int>> & dist) {
        for (auto e : adj[node]) {
            if (e == par)
                continue;

            int nodd = dist[node][0] - dist[e][1];
            int neven = dist[node][1] - dist[e][0];

            dist[e][0] += neven;
            dist[e][1] += nodd;

            reroot(e, node, adj, dist);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);

        for (auto e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for (auto e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<vector<int>> dist1(n, vector<int>(2)), dist2(m, vector<int>(2));

        dfs(0, -1, adj1, dist1);
        reroot(0, -1, adj1, dist1);
        dfs(0, -1, adj2, dist2);
        reroot(0, -1, adj2, dist2);
        int oddmax = 0;

        for(auto e:dist2) oddmax=max(oddmax,e[0]);

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = dist1[i][1] + oddmax;
        }

        return ans;
    }
};