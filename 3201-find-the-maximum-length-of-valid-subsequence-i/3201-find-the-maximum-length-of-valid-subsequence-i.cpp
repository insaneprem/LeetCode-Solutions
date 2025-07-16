class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto& pat : patterns) {
            int cnt = 0;
            for (auto num : nums) {
                if (num % 2 == pat[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        
        return res;
    }
};