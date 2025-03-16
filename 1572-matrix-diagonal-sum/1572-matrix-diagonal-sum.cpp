class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int i = 0, j = 0;

        while (i < mat.size() && j < mat[0].size())
            ans += mat[i][j], i++, j++;

        i = 0, j = mat[0].size() - 1;
        while (i < mat.size() && j >= 0)
            ans += mat[i][j], i++, j--;

        int val = 0;
        if (mat.size() % 2 == 1)
            val = mat[mat.size() / 2][mat.size() / 2];

        return ans - val;
    }
};