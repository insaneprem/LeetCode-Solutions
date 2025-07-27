class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), depth(n, 0);
        for (int i = 0; i < n; i++) {
            adj[i].push_back(favorite[i]);
            indegree[favorite[i]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto e : adj[node]) {
                if (--indegree[e] == 0)
                    q.push(e);
                depth[e] = max(depth[e], 1 + depth[node]);
            }
        }

        int maxCyclelenght = 0, lengthtwoConditon = 0;
        for (int node = 1; node < n; node++) {
            if (indegree[node] == 0)
                continue;

            int currnode = node, cyclelength = 0;
            while (indegree[currnode] != 0) {
                indegree[currnode] = 0;
                currnode = favorite[currnode];
                cyclelength++;
            }

            if (cyclelength == 2)
                lengthtwoConditon +=
                    depth[currnode] + depth[favorite[currnode]] + 2;
            else
                maxCyclelenght = max(maxCyclelenght, cyclelength);
        }

        return max(maxCyclelenght, lengthtwoConditon);
    }
};