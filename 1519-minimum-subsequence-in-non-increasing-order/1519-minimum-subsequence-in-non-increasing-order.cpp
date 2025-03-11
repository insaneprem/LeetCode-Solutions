class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int tsum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());

        int currsum=0;
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            tsum-=nums[i];
            ans.push_back(nums[i]);
    
            if(currsum>tsum) break;
        }

        return ans;
    }
};