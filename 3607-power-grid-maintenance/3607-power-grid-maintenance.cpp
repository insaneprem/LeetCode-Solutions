class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
        for (int i = 0; i <= n; i++)
            size.push_back(1);
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findpar(parent[node]);
    }

    void unionSize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv)
            return;

        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c);

        for (auto it : connections) {
            int u = it[0], v = it[1];
            dsu.unionSize(u, v);
        }

        vector<int> isOnline(c + 1, 1);
        map<int, set<int>> comp;

        for (int i = 1; i <= c; i++) {
            int parent = dsu.findpar(i);
            comp[parent].insert(i);
        }

        vector<int> ans;
        for (auto query : queries) {
            int type = query[0];
            int node = query[1];
            int parent = dsu.findpar(node);

            if (type == 1) {
                if (isOnline[node])
                    ans.push_back(node);
                else {
                    if (comp.count(parent)) {
                        int res = *comp[parent].begin();
                        ans.push_back(res);
                    }
                    else ans.push_back(-1);
                }
            } else {
                isOnline[node] = 0;
                comp[parent].erase(node);
                if (comp[parent].size() == 0)
                    comp.erase(parent);
            }
        }

        return ans;
    }
};