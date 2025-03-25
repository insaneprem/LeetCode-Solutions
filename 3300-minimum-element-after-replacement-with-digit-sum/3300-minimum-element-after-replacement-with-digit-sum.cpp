class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for (auto num : nums) {
            int currsum = 0;
            while (num)
                currsum += num % 10, num /= 10;
            ans = min(ans, currsum);
        }
        return ans;
    }
};