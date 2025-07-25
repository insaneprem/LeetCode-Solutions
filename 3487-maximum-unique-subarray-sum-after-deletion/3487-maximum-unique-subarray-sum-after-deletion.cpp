class Solution {
public:
    int maxSum(vector<int>& nums) {
        ranges::sort(nums);
        nums.erase(unique(begin(nums), end(nums)), end(nums));

        int ans = 0;
        bool ispos = 0;
        for (auto i : nums){
            if (i >= 0){
                ispos = 1;
                ans += i;
            }
        }

        if(!ispos) return *max_element(begin(nums),end(nums));
        
        return ans;
    }
};