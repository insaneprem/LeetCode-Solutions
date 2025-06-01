class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            unsigned long long pro1 = 1;
            unsigned long long pro2 = 1;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1)
                    pro1 *= nums[j];
                else
                    pro2 *= nums[j];
            }

            if (pro1 == target && pro2 == target)
                return 1;
        }

        return false;
    }
};