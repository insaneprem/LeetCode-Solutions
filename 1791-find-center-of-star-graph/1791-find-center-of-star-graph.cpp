class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> indegree(edges.size() + 2, 0);

        for (auto e : edges) {
            int u = e[0], v = e[1];
            indegree[u]++;
            indegree[v]++;
        }

        for (int i = 1; i < indegree.size(); i++) {
            cout << indegree[i] << " ";
            if (indegree[i] == edges.size())
                return i;
        }

        return -1;
    }
};