class Solution {
public:
    vector<int> ans;
    void dfs(int node, map<int, vector<int>>& adj, map<int, bool>& visited) {
        visited[node] = 1;

        for (auto e : adj[node]) {
            if (!visited[e])
                dfs(e, adj, visited);
        }

        ans.push_back(node);
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mp;
        map<int, int> indegree;
        for (auto e : adjacentPairs) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        map<int, bool> visited;
        for (auto it : indegree) {
            if (it.second == 1) {
                dfs(it.first, mp, visited);
                break;
            }
        }

        return ans;
    }
};