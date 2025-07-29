class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(32, -1); 
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    lastSeen[b] = i;
                }
            }

            int maxIdx = i;
            for (int b = 0; b < 32; b++) {
                if (lastSeen[b] != -1) {
                    maxIdx = max(maxIdx, lastSeen[b]);
                }
            }

            res[i] = maxIdx - i + 1;
        }

        return res;
    }
};
