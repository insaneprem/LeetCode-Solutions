class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> bits(32);

        for (auto& num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] > 0)
                ans += (1 << i);
        }
        return ans;
    }
};