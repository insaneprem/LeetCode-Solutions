class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[n - 1][m - 1];

        while (l <= r) {
            int mid = (l + r) / 2, cnt = 0;

            for (int i = 0; i < n; i++) {
                cnt += upper_bound(begin(matrix[i]), end(matrix[i]), mid) -
                       matrix[i].begin();
            }

            (cnt < k) ? l = mid + 1 : r = mid - 1;
        }

        return l;
    }
};