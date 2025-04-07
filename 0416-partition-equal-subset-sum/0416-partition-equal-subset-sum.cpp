class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int dp[20001]={};
        int n=nums.size();

        dp[0]=1;
        int sum=accumulate(begin(nums),end(nums),0);
        for(auto &num:nums){
            for(int i=20000;i-num>=0;i--) if(dp[i-num]) dp[i]=1;
        }

        return (sum%2 == 0 && dp[sum/2]);
    }
};