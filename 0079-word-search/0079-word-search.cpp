class Solution {
public:
    int n, m;
    string word;
    bool isValid(int r, int c) { return (r >= 0 && c >= 0 && r < n && c < m); }
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool dfs(int idx, int r, int c, vector<vector<char>>& grid) {
        if(idx >= word.size()) return true;

        if(!isValid(r,c) || grid[r][c] != word[idx]) return false;

        char temp = grid[r][c];
        grid[r][c] = '$';
        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(dfs(idx+1,nr,nc,grid)) return true;
        }
        grid[r][c] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string _word) {
        word = _word;
        n = board.size(), m = board[0].size();
        if(n * m < word.size()) return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(0, i, j, board)) {
                        return true;
                }
            }
        }
        return false;
    }
};