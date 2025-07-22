class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> st;

        int l = 0, r = 0, n = nums.size();
        int maxsum = 0, sum = 0;

        while (l < n && r < n) {
            while (r<n && st.find(nums[r]) == st.end()) {
                st.insert(nums[r]);
                sum += nums[r];
                r++;
            }
            maxsum = max(maxsum, sum);

            while (r<n && st.find(nums[r]) != st.end()) {
                sum -= nums[l];
                st.erase(nums[l]);
                l++;
            }
        }

        return max(maxsum, sum);
    }
};