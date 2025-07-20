class Solution {
public:
    long long n, k;
    typedef pair<long long,int> P;
    bool isValid(vector<vector<pair<int, int>>>& adj) {
        vector<long long> dist(n, 1e18);
        priority_queue<P, vector<P>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        this->n = online.size();
        this->k = k;
        int l = 0, r = 1e9, ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            vector<vector<pair<int, int>>> adj(n);

            for (auto& e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (w >= mid && (v == 0 || v == n - 1 || online[v])) {
                    adj[u].push_back({v, w});
                }
            }

            if (isValid(adj)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
