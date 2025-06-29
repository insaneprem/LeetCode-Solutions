class Solution {
public:
    const int MOD = 1e9 + 7;
    int power(long long base, int exp, int mod) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }

        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        long long ans = 0;
        ranges::sort(nums);

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + power(2LL, (right - left), MOD)) % MOD;
                left++;
            } else
                right--;
        }

        return ans;
    }
};