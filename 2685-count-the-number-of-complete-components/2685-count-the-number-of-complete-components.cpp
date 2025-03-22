class DSU{
    vector<int> parent,size,rank;
    public:
    DSU(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findpar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node]=findpar(parent[node]); // path compession
    }

    void unionSize(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);

        if(pu == pv) return;
         
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        } 
    }

    void unionRank(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);

        if(pu == pv) return;

        if(rank[pu] == rank[pv]){
            parent[pu]=pv;
            rank[pv]++;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }

    int sz(int n){
        return size[n];
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto e:edges) dsu.unionSize(e[0],e[1]);

        map<int,int> edgecnt;

        for(auto e:edges) edgecnt[dsu.findpar(e[0])]++;
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(dsu.findpar(i) == i) ans+=(dsu.sz(i)*(dsu.sz(i)-1)/2) == edgecnt[i];
        }
        return ans;
    }
};