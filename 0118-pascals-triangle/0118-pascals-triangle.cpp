class Solution {
public:
    int ncr(int n, int r) {
        int ans = 1;

        for (int i = 1; i <= min(r, n - r); i++) {
            ans = ans * (n - i + 1) / i;
        }

        return ans;
    }
    vector<int> generateRow(int rowNum) {
        vector<int> ans;

        for (int i = 0; i < rowNum + 1; i++)
            ans.push_back(ncr(rowNum, i));

        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i - 1));
        }

        return ans;
    }
};