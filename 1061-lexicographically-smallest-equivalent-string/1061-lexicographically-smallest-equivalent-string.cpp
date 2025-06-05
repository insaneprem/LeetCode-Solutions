class Solution {
public:
    vector<vector<int>> adj;         
    vector<bool> visited;            
    vector<char> minchar;            

    void dfs(int node, vector<int>& component, char& smallest) {
        visited[node] = true;
        component.push_back(node);
        smallest = min(smallest, (char)(node + 'a'));

        for (auto e : adj[node]) {
            if (!visited[e]) 
                dfs(e, component, smallest);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        adj.resize(26);
        visited.resize(26,false);
        minchar.resize(26);

        for (int i = 0; i < s1.size(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        for (int i = 0; i < 26; i++) {
            if (!visited[i]) {
                vector<int> component;
                char smallest = 'z';

                dfs(i, component, smallest);

                for (auto node : component) minchar[node] = smallest;
            }
        }

        string ans = "";
        for (auto i : baseStr) ans += minchar[i - 'a'];
        
        return ans;
    }
};
