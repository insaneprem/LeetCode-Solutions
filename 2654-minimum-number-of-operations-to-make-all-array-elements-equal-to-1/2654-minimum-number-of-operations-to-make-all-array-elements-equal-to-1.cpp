class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int onecnt = 0;
        int g = 0;
        for (auto i : nums) {
            if (i == 1) {
                onecnt++;
            }
            g = gcd(g, i);
        }
        if (onecnt > 0) {
            return n - onecnt;
        }
        if (g > 1) {
            return -1;
        }

        int min_len = n;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }
        return min_len + n - 2;
    }
};