class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int l = 0; l < n;) {
            if (nums[l] == 0) {
                int r = l;
                while (r < n && nums[r] == 0)
                    ans += r - l + 1, r++;
                l = r;
            }
            l++;
        }

        return ans;
    }
};