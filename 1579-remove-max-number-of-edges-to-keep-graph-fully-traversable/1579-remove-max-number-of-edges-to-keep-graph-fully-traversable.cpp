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
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(begin(edges), end(edges),
             [](auto a, auto b) { return a[0] > b[0]; });

        DSU A(n), B(n);
        int ans = 0;
        for (auto e : edges) {
            int type = e[0], u = e[1], v = e[2];

            bool Aconnected = A.findpar(u) == A.findpar(v);
            bool Bconnected = B.findpar(u) == B.findpar(v);

            if (type == 3) {
                if (Aconnected && Bconnected) {
                    ans++;
                    continue;
                }

                if (!Aconnected) {
                    A.unionSize(u, v);
                }

                if (!Bconnected) {
                    B.unionSize(u, v);
                }

            } else if (type == 2) {
                if (Bconnected) {
                    ans++;
                    continue;
                }
                B.unionSize(u, v);
            } else {
                if (Aconnected) {
                    ans++;
                    continue;
                }
                A.unionSize(u, v);
            }
        }

        // count how many components Alice has
        int compA = 0, compB = 0;
        for (int i = 1; i <= n; i++) {
            if (A.findpar(i) == i)
                compA++;
            if (B.findpar(i) == i)
                compB++;
        }
        if (compA > 1 || compB > 1)
            return -1;
        return ans;
    }
};