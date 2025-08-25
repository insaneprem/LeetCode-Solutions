class Solution {
public:
    const int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q:queries){
            int l = q[0] , r = q[1] , k = q[2] , val = q[3];

            for(int i=l;i<=r;i+=k){
                nums[i] = ((int) ((1LL * nums[i] * val)%mod)) % mod;
            }
        }
        
        int xr = 0;
        for(auto &i:nums) xr^=i;

        return xr;
    }
};