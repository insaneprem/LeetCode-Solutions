class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> temp(1, matrix[0][0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0) {
                    matrix[i][j] ^= matrix[i][j - 1];
                } else if (j == 0) {
                    matrix[i][j] ^= matrix[i - 1][j];
                } else {
                    matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^
                                    matrix[i - 1][j - 1];
                }
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.rbegin(), temp.rend());
        return temp[k - 1];
    }
};