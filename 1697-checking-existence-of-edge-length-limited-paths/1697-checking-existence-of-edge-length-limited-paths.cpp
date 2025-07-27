class DSU {
    vector<int> rank, parent;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++)
            rank.push_back(0);
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findpar(parent[node]);
    }

    void unionRank(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv)
            return;

        if (rank[pu] == rank[pv]) {
            rank[pu]++;
            parent[pv] = pu;
        } else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else
            parent[pu] = pv;
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        DSU dsu(n);
        int edgesize=edgeList.size();
        sort(begin(edgeList), end(edgeList),
             [](auto a, auto b) { return a[2] < b[2]; });

        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }

        sort(begin(queries), end(queries),
             [](auto a, auto b) { return a[2] < b[2]; });
        
        vector<bool> ans(queries.size());
        int idx=0;
        for(auto q:queries){
            int u=q[0],v=q[1],w=q[2],qidx=q[3];
             
            while(idx<edgesize && edgeList[idx][2]<w){
               dsu.unionRank(edgeList[idx][0],edgeList[idx][1]);
               idx++;
            } 

            ans[qidx] = dsu.findpar(u) == dsu.findpar(v);
        }

        return ans;
    }
};