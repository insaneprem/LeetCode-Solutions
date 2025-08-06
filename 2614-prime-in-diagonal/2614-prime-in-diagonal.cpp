class Solution {
public:
    bool isprime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || (n % (i + 2)) == 0)
                return false;
        }

        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0, n = nums.size(), m = nums[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == j || (j == m - 1 - i)) && isprime(nums[i][j]))
                    ans = max(ans,nums[i][j]);
            }
        }

        return ans;
    }
};