class Solution {
public:
    int countElements(vector<int>& nums) {
        if(count(begin(nums),end(nums),*max_element(begin(nums),end(nums))) == nums.size()) return 0;
        return nums.size() - count(begin(nums),end(nums),*max_element(begin(nums),end(nums)))
        - count(begin(nums),end(nums),*min_element(begin(nums),end(nums)));
    }
};