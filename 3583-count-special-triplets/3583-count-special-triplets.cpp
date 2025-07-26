class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        map<int, int> freqprev, freqnext;

        for (auto i : nums)
            freqprev[i]++;

        freqnext[nums[n - 1]]++;

        int ans = 0;

        for (int i = n - 2; i >= 0; i--) {
            int right = freqnext[nums[i] * 2];
            freqnext[nums[i]]++;
            int left = freqprev[nums[i] * 2] - freqnext[nums[i] * 2];

            long long val = (1LL * right * left) % MOD;
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};