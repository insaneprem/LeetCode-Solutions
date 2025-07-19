class Solution {
public:
    void dijkstra(int src, vector<pair<int, int>> adj[], vector<int>& dist) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int distsofar = pq.top().first;
            pq.pop();

            if (distsofar > dist[u])
                continue;

            for (auto e : adj[u]) {
                int v = e.first;
                int w = e.second;

                if (distsofar + w < dist[v]) {
                    dist[v] = distsofar + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e8);
        vector<pair<int, int>> adj[n + 1];

        for (auto e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        dijkstra(k, adj, dist);

        int ans = 0;
        for (int i = 1; i < dist.size(); i++) {
            // cout<<e<<" ";
            ans = max(ans, dist[i]);
        }

        return ans == 1e8 ? -1 : ans;
    }
};