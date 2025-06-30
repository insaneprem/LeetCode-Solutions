class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;

        ranges::sort(nums);
        map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
            if (freq[i - 1])
                ans = max(ans, freq[i] + freq[i - 1]);
        }

        return ans;
    }
};