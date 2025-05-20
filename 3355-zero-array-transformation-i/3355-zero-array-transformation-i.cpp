class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> temp(n+2,0);

        for(auto q:queries){
           int l=q[0];
           int r=q[1];

           temp[l]++;
           if(r<n) temp[r+1]--;
        }

        for(int i=1;i<n;i++) temp[i]+=temp[i-1];

        for(int i=0;i<n;i++) if(temp[i]<nums[i]) return 0;
        return 1;
    }
};