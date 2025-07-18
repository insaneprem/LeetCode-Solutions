class DSU {
    vector<int> parent, size, rank;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findpar(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findpar(parent[node]); // path compession
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
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);

        for(auto e:edges) dsu.unionRank(e[0],e[1]);

        map<int,int> mpp;

        for(auto e:edges){
            int root=dsu.findpar(e[0]);
            if(mpp.find(root) == mpp.end()) mpp[root]=e[2];
            else mpp[root] = mpp[root] & e[2];
        }

        vector<int> ans;

        for(auto q:query){
            ans.push_back((dsu.findpar(q[0]) == dsu.findpar(q[1])) ? mpp[dsu.findpar(q[1])] : -1);
        }

        return ans;


    }
};