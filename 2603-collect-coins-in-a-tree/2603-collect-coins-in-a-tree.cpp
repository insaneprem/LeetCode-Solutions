class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q, lwc;

        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1)
                q.push(i);
        }

        int remcoin = n;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (coins[node]) {
                lwc.push(node);
                continue;
            }

            remcoin--;

            for (auto e : adj[node]) {
                auto it = find(begin(adj[node]), end(adj[node]), e);
                auto it2 = find(begin(adj[e]), end(adj[e]), node);

                adj[e].erase(it2);
                adj[node].erase(it);

                if (adj[e].size() == 1)
                    q.push(e);
            }
        }

        for (int i = 0; i < 2; i++) {
            int sz = lwc.size();

            for (int j = 0; j < sz; j++) {
                int node = lwc.front();
                lwc.pop();

                remcoin--;

                for (auto e : adj[node]) {
                    auto it = find(begin(adj[node]), end(adj[node]), e);
                    auto it2 = find(begin(adj[e]), end(adj[e]), node);

                    adj[e].erase(it2);
                    adj[node].erase(it);

                    if (adj[e].size() == 1)
                        lwc.push(e);
                }
            }
        }

        if (remcoin == 0)
            return 0;

        return (remcoin - 1) * 2;
    }
};