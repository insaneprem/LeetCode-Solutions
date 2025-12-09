class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        map<int, int> freq, prefix;

        for (auto& i : nums)
            freq[i]++;

        int ans = 0;
        for (auto& i : nums) {
            int db = i * 2;
            int left = prefix[db];
            int right = freq[db] - left - (i == db);
            ans = (ans + (1LL * left * right)) % MOD;

            prefix[i]++;
        }

        return ans;
    }
};