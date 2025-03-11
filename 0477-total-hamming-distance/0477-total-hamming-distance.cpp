class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bits(32);

        for (auto i : nums) {
            for (int j = 0; j < 32; j++) {
                if (i & (1 << j))
                    bits[j]++;
            }
        }

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++) {
            if (bits[i] == 0 || bits[i] == n)
                continue;
            ans += ((n - bits[i]) *  bits[i]);
        }

        return ans;
    }
};