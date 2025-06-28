class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int l = 0, r = 0, n = s.size();
        int ans = 1;
        map<char, int> mpp;
        while (r < n) {
            while (mpp.find(s[r]) != mpp.end()) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            mpp[s[r]]++;
            r++;
        }
        return ans;
    }
};