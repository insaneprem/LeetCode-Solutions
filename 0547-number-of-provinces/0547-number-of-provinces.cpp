class DSU {
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findpar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findpar(parent[node]); // path compression
    }
    
    void unionSize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
    void unionRank(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
            return;
        if (rank[pu] == rank[pv]) {
            parent[pu] = pv;
            rank[pv]++;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
        }
    }
    
    int count() {
        set<int> s;
        for (int i = 0; i < parent.size(); i++) {
            s.insert(findpar(i));
        }
        return s.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  
                if (isConnected[i][j] == 1) {
                    dsu.unionRank(i, j);
                }
            }
        }
        return dsu.count();
    }
};
