class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans(1,nums[0]);

        for(int i=1;i<nums.size();i++){
            int curr=nums[i];

            while(ans.size() && gcd(curr,ans.back()) >1){
                int top=ans.back();
                ans.pop_back();
                curr=lcm(top,curr);
            }
            ans.push_back(curr);
        }

        return ans;
    }
};