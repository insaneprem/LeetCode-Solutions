class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());

        long long ans = (long long) ((long long) k * (k + 1)) / 2;

        for (auto i : st) {
            if (i <= k) {
                ans += k + 1;
                ans -= i;
                k++;
            } 
            else break;
        }
        return ans;
    }
};