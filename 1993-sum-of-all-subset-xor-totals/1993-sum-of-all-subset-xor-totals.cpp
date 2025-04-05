class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, temp;

        for (int i = 0; i < (1 << nums.size()); i++) {
            temp = 0;
            for (int j = 0; j < nums.size(); j++)
                if ((i >> j) & 1)
                    temp ^= nums[j];
            ans += temp;
        }

        return ans;
    }
};