class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1], val = 0, total = 0, p = 1;
            
            while (p <= r) val++, p *= 4;
            
            for (int i = 0, p = 1; p <= r; p *= 4, i++) {
                long long low = max(l, (long long)p) , high = min(r, (long long)p * 4 - 1);            
                
                if (low <= high)  total += (i + 1) * (high - low + 1);
            }
            
            ans += max(val, (total + 1) / 2);
        }
        return ans;
    }
};
