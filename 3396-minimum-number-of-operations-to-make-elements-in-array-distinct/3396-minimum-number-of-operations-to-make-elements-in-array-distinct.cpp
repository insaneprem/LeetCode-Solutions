class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), idx = n - 1;
        vector<bool> visited(101, 0);

        for (idx; idx >= 0; idx--) {
            if (visited[nums[idx]]) break;
            visited[nums[idx]] = 1;
        }

        return (idx + 3) / 3;
    }
};