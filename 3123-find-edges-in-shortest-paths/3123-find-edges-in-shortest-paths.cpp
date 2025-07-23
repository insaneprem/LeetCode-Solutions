class Solution {
public:
    void dijkstra(int src, vector<vector<pair<int, int>>>& adj,
                  vector<int>& dist) {
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dist_so_far, u] = pq.top();
            pq.pop();

            if (dist_so_far > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist_so_far + w) {
                    dist[v] = dist_so_far + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> fdist(n, 1e9), bdist(n, 1e9);
        dijkstra(0, adj, fdist);
        dijkstra(n - 1, adj, bdist);

        int distbetween = fdist[n - 1];
        vector<bool> ans;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            bool flag = false;
            if (fdist[u] + w + bdist[v] == distbetween ||
                bdist[u] + w + fdist[v] == distbetween)
                flag = 1;

            ans.push_back(flag);
        }

        return ans;
    }
};