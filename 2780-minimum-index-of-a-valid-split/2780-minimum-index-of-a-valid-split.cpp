class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size() , candidate = -1, vote = 0;
        for (auto num : nums) {
            if (vote == 0) candidate = num;
            vote += (num == candidate) ? 1 : -1;
        }

        int total = count(nums.begin(), nums.end(), candidate);
        if (total * 2 <= n) return -1;


        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) cnt++;
            if (cnt * 2 > (i + 1) && (total-cnt) * 2 > (n - i - 1)) return i;
        }

        return -1;
    }
};
