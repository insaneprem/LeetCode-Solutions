class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums),end(nums));
      
        for(int i=0;i<1001;i++){
            int greater=nums.size()-(lower_bound(begin(nums),end(nums),i)-nums.begin());
            if(greater == i) return i;
        }
        return -1;
    }
};