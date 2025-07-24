class Solution {
public:
    int indp1[100005], outdp1[100005], indp2[100005], outdp2[100005];

    void dfs1(int node, int par, vector<vector<int>>& adj) {
        indp1[node] = 0;
        for (auto e : adj[node]) {
            if (e == par) continue;
            dfs1(e, node, adj);
            indp1[node] = max(indp1[node], indp1[e] + 1);
        }
    }

    void dfs2(int node, int par, vector<vector<int>>& adj) {
        indp2[node] = 0;
        for (auto e : adj[node]) {
            if (e == par) continue;
            dfs2(e, node, adj);
            indp2[node] = max(indp2[node], indp2[e] + 1);
        }
    }

    void reroot1(int node, int par, vector<vector<int>>& adj) {
        int maxi1 = -1, maxi2 = -1, maxchild = -1;
        for (auto e : adj[node]) {
            if (e == par) continue;
            int val = 1 + indp1[e];
            if (val > maxi1) {
                maxi2 = maxi1;
                maxi1 = val;
                maxchild = e;
            } else if (val > maxi2) {
                maxi2 = val;
            }
        }
        for (auto e : adj[node]) {
            if (e == par) continue;
            int len = (e == maxchild) ? maxi2 : maxi1;
            outdp1[e] = 1 + max(outdp1[node], len);
            reroot1(e, node, adj);
        }
    }

    void reroot2(int node, int par, vector<vector<int>>& adj) {
        int maxi1 = -1, maxi2 = -1, maxchild = -1;
        for (auto e : adj[node]) {
            if (e == par) continue;
            int val = 1 + indp2[e];
            if (val > maxi1) {
                maxi2 = maxi1;
                maxi1 = val;
                maxchild = e;
            } else if (val > maxi2) {
                maxi2 = val;
            }
        }
        for (auto e : adj[node]) {
            if (e == par) continue;
            int len = (e == maxchild) ? maxi2 : maxi1;
            outdp2[e] = 1 + max(outdp2[node], len);
            reroot2(e, node, adj);
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;  

        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, adj1);
        reroot1(0, -1, adj1);
        dfs2(0, -1, adj2);
        reroot2(0, -1, adj2);

        int radius1 = INT_MAX, diameter1 = 0;
        for (int i = 0; i < n; i++) {
            int val = max(indp1[i], outdp1[i]);
            radius1   = min(radius1, val);
            diameter1 = max(diameter1, val);
        }

        
        int radius2 = INT_MAX, diameter2 = 0;
        for (int i = 0; i < m; i++) {              
            int val = max(indp2[i], outdp2[i]);
            radius2   = min(radius2, val);
            diameter2 = max(diameter2, val);
        }

        return max({ diameter1, diameter2, radius1 + radius2 + 1 });
    }
};
