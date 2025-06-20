class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        
        int ans=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>=nums[j]){
                    dp[i]=max(dp[j]+1,dp[i]);
                    ans=max(ans,dp[i]);
                }
            }
        }

        return nums.size()-ans;
    }
};