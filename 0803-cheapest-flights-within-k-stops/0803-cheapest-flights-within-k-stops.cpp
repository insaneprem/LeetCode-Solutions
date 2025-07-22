typedef pair<int, int> P;
typedef pair<int, P> T;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<P>> adj(n);
        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));
        dp[src][0] = 0;
        for (auto e : flights)
            adj[e[0]].push_back({e[1], e[2]});

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, {src, 0}});
        while (!pq.empty()) {
            int popnode = pq.top().second.first;
            int stops = pq.top().second.second;
            int distsofar = pq.top().first;
            pq.pop();

            if (distsofar != dp[popnode][stops] || stops == k + 1)
                continue;

            for (auto e : adj[popnode]) {
                int node = e.first;
                int distadd = e.second;

                if (distadd + distsofar < dp[node][stops + 1]) {
                    dp[node][stops + 1] = distadd + distsofar;
                    pq.push({dp[node][stops + 1], {node, stops + 1}});
                }
            }
        }

        int ans = *min_element(dp[dst].begin(), dp[dst].end());

        return (ans == INT_MAX ? -1 : ans);
    }
};