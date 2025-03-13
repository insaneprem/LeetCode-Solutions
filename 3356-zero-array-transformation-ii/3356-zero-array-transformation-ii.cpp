class Solution {
public:
    bool possible(int mid, const vector<int>& nums, const vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> temp(n, 0);
        
        for (int i = 0; i < mid; i++) {
            int left = queries[i][0], right = queries[i][1], val = queries[i][2];
            temp[left] += val;
            if (right + 1 < n)
                temp[right + 1] -= val;
        }
        
        partial_sum(temp.begin(), temp.end(), temp.begin());
        
        for (int i = 0; i < n; i++) {
            if (temp[i] < nums[i])
                return false;
        }
        
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int left = 0, right = n;
        
        if (!possible(right, nums, queries))
            return -1;
        
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid, nums, queries)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
