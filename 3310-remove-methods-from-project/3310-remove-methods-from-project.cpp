typedef int ll;
class Hash {
private:
    map<tuple<int, int, int>, int> hash_table;

public:
    Hash() {}
    int hash(int x) { return hash({x, 0, 0}); }
    int hash(tuple<int, int> x) { return hash({get<0>(x), get<1>(x), 0}); }
    int hash(tuple<int, int, int> x) {
        if (hash_table.find(x) != hash_table.end())
            return hash_table[x];
        int new_hash = hash_table.size();
        hash_table[x] = new_hash;
        return new_hash;
    }
};

class Graph {

    bool is_directed;

public:
    vector<vector<pair<int, ll>>> adj;
    int n, N = 5000000;
    Hash h;

    Graph(int n_, bool is_directed_ = true) {
        n = n_;
        N = n + 1;
        is_directed = is_directed_;
        adj.resize(N, vector<pair<int, ll>>());
    }

    int hash(int u, int v) { return h.hash({u, v}); }
    int hash(int u, int v, int k) { return h.hash({u, v, k}); }

    void add_edge(int uR, int vR, ll c = 0) {
        int u = h.hash(uR), v = h.hash(vR);
        add_edge_internal(u, v, c);
    }
    void add_edge(tuple<int, int> uR, tuple<int, int> vR, ll c = 0) {
        int u = h.hash(uR), v = h.hash(vR);
        add_edge_internal(u, v, c);
    }
    void add_edge(tuple<int, int, int> uR, tuple<int, int, int> vR, ll c = 0) {
        int u = h.hash(uR), v = h.hash(vR);
        add_edge_internal(u, v, c);
    }

private:
    void add_edge_internal(int u, int v, ll c = 0) {
        add_edge_weighted_undirected(u, v, c);
        if (!is_directed)
            add_edge_weighted_undirected(v, u, c);
    }
    void add_edge_weighted_undirected(int u, int v, ll c) {
        pair<int, ll> p = make_pair(v, c);
        adj[u].push_back(p);
    }
};

class BFS {
    vector<ll> min_dist_from_source;
    vector<bool> visited;
    Graph* g;

public:
    BFS(Graph* g_) {
        g = g_;
        clear();
    }

    void clear() {
        min_dist_from_source.clear();
        min_dist_from_source.resize(g->N, -1);
        visited.clear();
        visited.resize(g->N, false);
    }

    void run(int sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
    }
    void run(tuple<int, int> sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
    }
    void run(tuple<int, int, int> sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
    }

    int min_dist(int targetR) {
        int target = (g->h).hash(targetR);
        return min_dist_internal(target);
    }
    int min_dist(tuple<int, int> targetR) {
        int target = (g->h).hash(targetR);
        return min_dist_internal(target);
    }
    int min_dist(tuple<int, int, int> targetR) {
        int target = (g->h).hash(targetR);
        return min_dist_internal(target);
    }

    bool is_visited(int targetR) {
        int target = (g->h).hash(targetR);
        return is_visited_internal(target);
    }
    bool is_visited(tuple<int, int> targetR) {
        int target = (g->h).hash(targetR);
        return is_visited_internal(target);
    }
    bool is_visited(tuple<int, int, int> targetR) {
        int target = (g->h).hash(targetR);
        return is_visited_internal(target);
    }

private:
    void run_internal(int source) {
        queue<int> q;
        q.push(source);

        visited[source] = true;
        min_dist_from_source[source] = 0;

        while (!q.empty()) {
            int cur_node = q.front();
            for (unsigned int i = 0; i < (g->adj[cur_node]).size(); ++i) {
                int adj_node = (g->adj[cur_node])[i].first;
                if (visited[adj_node] == false) {
                    visited[adj_node] = true;
                    min_dist_from_source[adj_node] =
                        min_dist_from_source[cur_node] + 1;
                    q.push(adj_node);
                }
            }
            q.pop();
        }

        return;
    }

    int min_dist_internal(int target) { return min_dist_from_source[target]; }

    bool is_visited_internal(int target) { return visited[target]; }
};

class Dijkstra {
    vector<long long> min_dist_from_source;
    Graph* g;

public:
    Dijkstra(Graph* g_) {
        g = g_;
        clear();
    }

    void clear() {
        min_dist_from_source.clear();
        min_dist_from_source.resize(
            g->N, LLONG_MAX); 
    }

    void run(int sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
    }
    void run(tuple<int, int> sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
    }
    void run(tuple<int, int, int> sourceR) {
        int source = (g->h).hash(sourceR);
        run_internal(source);
    }

    long long min_dist(int targetR) { 
        int target = (g->h).hash(targetR);
        return min_dist_internal(target);
    }
    long long min_dist(tuple<int, int> targetR) {
        int target = (g->h).hash(targetR);
        return min_dist_internal(target);
    }
    long long min_dist(tuple<int, int, int> targetR) {
        int target = (g->h).hash(targetR);
        return min_dist_internal(target);
    }

private:
    void run_internal(int source) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        min_dist_from_source[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [dist, cur_node] = pq.top();
            pq.pop();

            if (dist > min_dist_from_source[cur_node])
                continue;

            for (auto [adj_node, weight] : g->adj[cur_node]) {
                
                if (dist == LLONG_MAX)
                    continue; 
                              

                
                if (dist <= LLONG_MAX - weight) { 
                    long long new_dist = dist + weight;
                    if (min_dist_from_source[adj_node] > new_dist) {
                        min_dist_from_source[adj_node] = new_dist;
                        pq.push({new_dist, adj_node});
                    }
                }
            }
        }
    }

    long long min_dist_internal(int target) {
        return min_dist_from_source[target];
    }
};
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        Graph graph1(n),graph2(n+1);

        for(auto &edge:invocations){
            graph1.add_edge(edge[0],edge[1]);
            graph2.add_edge(edge[0],edge[1]);
        }

        BFS bfs(&graph1);
        bfs.run(k);
        vector<int> safe;
        set<int> danger;
        for(int i=0;i<n;i++){ 
            if(!bfs.is_visited(i)) safe.push_back(i);
            else danger.insert(i);
        }
        
        for(auto i:safe){ 
            cout<<i<<" ";
            graph2.add_edge(-1,i);
        }
        
        BFS bfs2(&graph2);
        bfs2.run(-1);

        vector<int> ans;
        bool flag=0;
        for(int i=0;i<n;i++){ 
            if(bfs2.is_visited(i)){ 
                ans.push_back(i);
                if(danger.find(i) != danger.end()) flag=1;
            }
        }
        
        vector<int> temp(n);
        iota(temp.begin(),temp.end(),0);
        if(flag) return temp;
        return ans;

    }
};