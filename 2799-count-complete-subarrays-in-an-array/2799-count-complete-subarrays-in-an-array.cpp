class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size(), right = 0;
        map<int, int> cnt;
        set<int> distinct(nums.begin(), nums.end());
        int distinctcnt = distinct.size();

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) cnt.erase(remove);
            }

            while (right < n && cnt.size() < distinctcnt) {
                int add = nums[right];
                cnt[add]++;
                right++;
            }

            if (cnt.size() == distinctcnt) ans += (n - right + 1);
        }
        
        return ans;
    }
};