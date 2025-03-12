class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int ans=0;
        for (int i = 0; i < n; i++) {
            string str = nums[i];
            for (int j = 0; j < n; j++) {
                if (i == j)  continue;
                string temp=str+nums[j];
                if(temp == target) ans++;
            }
        }

        return ans;
    }
};