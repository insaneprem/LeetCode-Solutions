class Solution {
public:
    typedef pair<int, int> P;
    vector<P> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();

        vector<P> arr;
        for (int i = 0; i < queries.size(); i++)
            arr.push_back({queries[i], i});

        ranges::sort(arr);

        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<>> pq;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        int points = 0;
        vector<int> ans(queries.size());

        for (auto q : arr) {
            while (!pq.empty() && pq.top().first < q.first) {
                int row = pq.top().second.first, col = pq.top().second.second;
                pq.pop();

                points++;

                for (auto d : dir) {
                    int nrow = row + d.first;
                    int ncol = col + d.second;

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        !visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
            ans[q.second] = points;
        }
        return ans;
    }
};
