class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minkidx = -1, maxkidx = -1, cultidx = -1, n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == minK)
                minkidx = i;
            if (nums[i] == maxK)
                maxkidx = i;
            if (nums[i] > maxK || nums[i] < minK)
                cultidx = i;

            ans += max(0LL, (long long)(min(minkidx, maxkidx) - cultidx));
        }

        return ans;
    }
};