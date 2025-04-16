class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;
        long long currentpair = 0;
        long long ans = 0;

        for (int left = 0, right = 0; right < n; right++) {
            currentpair+=freq[nums[right]];
            freq[nums[right]]++;

            while(currentpair>=k){
                ans+=(n-right);
                currentpair-=(freq[nums[left]]-1);
                freq[nums[left]]--;
                left++;
            }
        }


        return ans;
    }
};