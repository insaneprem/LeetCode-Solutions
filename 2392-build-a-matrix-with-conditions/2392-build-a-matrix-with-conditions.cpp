class Solution {
public:
    vector<int> rowvec, colvec;
    bool cycledetected = false;

    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, string turn) {
        visited[node] = 1;

        for (auto e : adj[node]) {
            if (visited[e] == 0) {
                dfs(e, visited, adj, turn);
                if (cycledetected) return;
            } else if (visited[e] == 1) {
                cycledetected = true;
                return;
            }
        }

        visited[node] = 2;
        (turn == "row" ? rowvec : colvec).push_back(node);
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowadj(k + 1), coladj(k + 1);

        for (auto r : rowConditions) {
            int u = r[0], v = r[1];
            rowadj[u].push_back(v);
        }

        for (auto c : colConditions) {
            int u = c[0], v = c[1];
            coladj[u].push_back(v);
        }

        vector<int> rowvis(k + 1, 0), colvis(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            if (!rowvis[i]) {
                dfs(i, rowvis, rowadj, "row");
                if (cycledetected)
                    return {};
            }
        }
        reverse(begin(rowvec), end(rowvec));

        for (int i = 1; i <= k; i++) {
            if (!colvis[i]) {
                dfs(i, colvis, coladj, "col");
                if (cycledetected)
                    return {};
            }
        }
        reverse(begin(colvec), end(colvec));

        unordered_map<int, int> mprow, mpcol;
        for (int i = 0; i < rowvec.size(); i++) {
            mprow[rowvec[i]] = i;
        }
        for (int i = 0; i < colvec.size(); i++) {
            mpcol[colvec[i]] = i;
        }

        vector<vector<int>> mat(k, vector<int>(k, 0));

        for (int i = 1; i <= k; i++) {
            int r = mprow[i];
            int c = mpcol[i];
            mat[r][c] = i;
        }

        return mat;
    }
};
