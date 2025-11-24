class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int sum = 0;
        vector<bool> ans;
        for (auto& i : nums) {
            sum = sum << 1;
            if (i == 1)
                sum += 1;
            sum %= 5;
            if (sum == 0)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};