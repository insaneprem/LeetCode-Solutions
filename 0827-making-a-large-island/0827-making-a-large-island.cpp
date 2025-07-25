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

        if (size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }

    int sz(int node) { return size[findpar(node)]; }
};
class Solution {
public:
    int n, m;
    int coordinate(int i, int j) { return i * m + j; }
    bool isValid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int largestIsland(vector<vector<int>>& grid) {

        this->n = grid.size(), this->m = grid[0].size();
        DSU dsu(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int cord = coordinate(i, j);

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirs[k][0];
                        int nj = j + dirs[k][1];
                        int cord2 = coordinate(ni, nj);

                        if (isValid(ni, nj) && grid[ni][nj] &&
                            dsu.findpar(cord) != dsu.findpar(cord2)) {
                            dsu.unionSize(cord, cord2);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j]) {
                    ans = max(ans, dsu.sz(coordinate(i, j)));
                    continue;
                }

                int val = 0;
                unordered_set<int> unique_parents;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirs[k][0];
                    int nj = j + dirs[k][1];

                    if (isValid(ni, nj) && grid[ni][nj]) {
                        int par = dsu.findpar(coordinate(ni, nj));
                        if (unique_parents.insert(par).second) {
                            val += dsu.sz(par);
                        }
                    }
                }
                ans = max(ans, val + 1);
            }
        }

        return ans;
    }
};