class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 101;
        for (int i = 0; i + k <= blocks.size(); i++) {
            string str = blocks.substr(i, k);
            int val = count(str.begin(), str.end(), 'W');
            ans = min(ans, val);
        }
        return ans;
    }
};