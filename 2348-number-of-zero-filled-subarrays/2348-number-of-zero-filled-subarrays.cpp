class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int zerocnt = 0;
        for (auto num : nums) {
            if (num == 0)
                zerocnt++;
            else
                zerocnt = 0;

            ans += zerocnt;
        }

        return ans;
    }
};