class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0, n = nums.size();
        long long sum = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right]; 

            while (left <= right && sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }

            ans += (right - left + 1);  
        }
        
        return ans;
    }
};
