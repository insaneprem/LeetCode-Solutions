class Graph {
public:
    typedef pair<int, int> P;
    vector<vector<P>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
    }

    int shortestPath(int node1, int node2) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, node1});

        int n = adj.size();
        vector<int> dist(n, 1e9);
        dist[node1] = 0;

        while (!pq.empty()) {
            auto [dist_so_far, u] = pq.top();
            pq.pop();

            if (dist_so_far > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (dist_so_far + w < dist[v]) {
                    dist[v] = dist_so_far + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[node2] == 1e9 ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */