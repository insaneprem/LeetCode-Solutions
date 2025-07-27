class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<set<int>> ancestors(n);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                
                for (auto anc : ancestors[node])
                    ancestors[neighbor].insert(anc);

                
                ancestors[neighbor].insert(node);

                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return res;
    }
};
