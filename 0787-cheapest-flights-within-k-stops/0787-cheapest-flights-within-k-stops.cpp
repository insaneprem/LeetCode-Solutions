class Solution {
public:
    typedef pair<int, int> P;
    void dijkstra(int k, int src, vector<vector<P>> adj,
                  vector<vector<int>>& dp) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [dist_so_far, u, stop] = pq.top();
            pq.pop();

            if (dist_so_far > dp[u][stop] || (stop == k + 1))
                continue;

            for (auto [v, w] : adj[u]) {
                if (dist_so_far + w < dp[v][stop + 1]) {
                    dp[v][stop + 1] = dist_so_far + w;
                    pq.push({dp[v][stop + 1], v, stop + 1});
                }
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<P>> adj(n);
        for (auto e : flights) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        vector<vector<int>> dp(n, vector<int>(k + 2, 1e9));
        dijkstra(k, src, adj, dp);

        int ans = *min_element(dp[dst].begin(), dp[dst].end());
        return ans == 1e9 ? -1 : ans;
    }
};