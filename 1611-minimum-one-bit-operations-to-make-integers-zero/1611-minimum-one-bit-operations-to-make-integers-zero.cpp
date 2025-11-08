class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long> bit(32, 0);
        bit[0] = 1;

        for (int i = 1; i < 32; i++) {
            bit[i] = (2 * bit[i - 1]) + 1;
        }

        int sign = 1;

        long long ans = 0;

        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                ans += bit[i] * sign;
                sign *= -1;
            }
        }

        return ans;
    }
};