class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {

        int n = nums.size();
        set<vector<int>> ans;

        int i, j;
        for (i = 0; i < n; i++) {
            vector<int> temp;
            int cnt = 0;
            for (j = i; j < n; j++) {
                temp.push_back(nums[j]);
                if (nums[j] % p == 0) cnt++;
                if (cnt > k) break;
                
                ans.insert(temp);
            }
        }

        return ans.size();
    }
};