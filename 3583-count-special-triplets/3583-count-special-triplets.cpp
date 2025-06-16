class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, int> freqLeft;
        unordered_map<int, int> freqRight;

        for (int i = 0; i < n; i++) {
            freqRight[nums[i]]++;
        }

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            freqRight[nums[j]]--;  

            int twice = nums[j] * 2;
            ans = (ans + 1LL * freqLeft[twice] * freqRight[twice]) % MOD;

            freqLeft[nums[j]]++; 
        }

        return ans;
    }
};
