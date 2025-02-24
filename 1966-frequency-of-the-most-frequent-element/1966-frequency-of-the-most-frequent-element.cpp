class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ranges::sort(nums); 

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int l = -1, r = i; 

            while (r - l > 1) { 
                int mid = (l + r) / 2;

                long long cost = (long long) nums[i] * (i - mid + 1) - (prefix[i + 1] - prefix[mid]);

                (cost <= k) ? r = mid : l = mid;
            }

            ans = max(ans, i - r + 1);
        }

        return ans;
    }
};
