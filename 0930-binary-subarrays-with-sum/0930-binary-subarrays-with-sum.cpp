class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> mp;
        mp[0] = 1;

        int currsum = 0;
        int ans = 0;
        for (auto i : nums) {
            currsum += i;

            if (mp.find(currsum - goal) != mp.end())
                ans += mp[currsum - goal];
            mp[currsum]++;
        }

        return ans;
    }
};