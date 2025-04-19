class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        long long ans(0);
        long long cnt=0;

        for(auto num:nums){
            long long low=lower_bound(nums.begin(),nums.end(),lower-num)-nums.begin();
            long long up=upper_bound(nums.begin(),nums.end(),upper-num)-nums.begin()-1;

            long long val=(low>cnt) ? up-max(low,cnt)+1 : up-max(low,cnt);

            if(val<0) break;
            
            ans+=val;
            cnt++;
        }
        //0 1 4 4 5 7
        return ans;
    }
};