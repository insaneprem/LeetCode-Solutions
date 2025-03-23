class Solution {
public:
    const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long distsofar = pq.top().first;
            int node = pq.top().second;
            pq.pop();

           
            if (distsofar != dist[node]) continue;

            for (auto e : adj[node]) {
                int ne = e.first;
                int d = e.second;

                if (distsofar + d < dist[ne]) {
                    dist[ne] = distsofar + d;
                    ways[ne] = ways[node];
                    pq.push({dist[ne], ne});
                }
                else if (distsofar + d == dist[ne]) {
                    ways[ne] = (ways[ne] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
