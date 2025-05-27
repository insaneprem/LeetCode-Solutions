class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> dp(n);
        sort(begin(nums),end(nums));
        
        for(int i=0;i<n;i++) dp[i]={1,i};
        
        int maxi=1,maxind=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j].first>=dp[i].first && nums[i]%nums[j] == 0){
                    dp[i].first=dp[j].first+1;
                    dp[i].second=j;
                }
            }
            if(dp[i].first>maxi){
                maxi=dp[i].first;
                maxind=i;
            }
        } 

        vector<int> ans;
        for(auto i:dp) cout<<i.first<<" "<<i.second<<"\n";
        cout<<maxind;
        while(dp[maxind].second != maxind){
            // cout<<maxind<<" ";
            ans.push_back(nums[maxind]);
            maxind=dp[maxind].second;
        }
        ans.push_back(nums[maxind]);

        reverse(begin(ans),end(ans));

        return ans;

    }
};