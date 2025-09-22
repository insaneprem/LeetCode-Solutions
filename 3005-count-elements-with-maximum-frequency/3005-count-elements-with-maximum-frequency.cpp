class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int maxFreq = 0, ans = 0;

        for (auto& num : nums) {
            mp[num]++;
            if (mp[num] > maxFreq) {
                ans = mp[num];
                maxFreq = ans;
            } else if (mp[num] == maxFreq) {
                ans += mp[num];
            }
        }

        return ans;
    }
};