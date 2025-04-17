class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ans += (nums[i] == nums[j] && (i * j) % k == 0);
            }
        }

        return ans;
    }
};