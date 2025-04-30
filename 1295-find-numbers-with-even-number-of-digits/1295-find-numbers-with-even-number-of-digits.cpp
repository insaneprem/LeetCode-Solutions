class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) {
            ans += !(to_string(i).length() & 1);
        }
        return ans;
    }
};