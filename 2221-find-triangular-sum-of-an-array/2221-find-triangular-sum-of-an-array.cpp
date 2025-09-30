class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> prevdp = nums,temp;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            temp.clear();
            int sz = prevdp.size();
            for (int j = 0; j + 1 < sz; j++)
                temp.push_back((prevdp[j] + prevdp[j + 1]) % 10);
            
            prevdp = move(temp);
        }

        return prevdp[0];
    }
};