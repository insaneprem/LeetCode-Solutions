class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ranges::sort(nums);
        
        int inc=0;
        for(int i=1;i<nums.size();i++){
           while(nums[i] <= nums[i-1]){
             nums[i]++;
             inc++;
           }
        }
        return inc;
    }
};