class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        multiset<string> st;
        int ans = 0;

        for (auto i : words) {
            string rev = i;
            reverse(begin(rev), end(rev));

            if (st.count(rev)) {
                cout<<i<<" ";
                ans += 4;
                st.erase(st.find(rev));
            } else {
                st.insert(i);
            }
        }

        for (auto i : st) {
            if (i[0] == i[1]) {
                // cout<<i;
                ans += 2;
                break;
            }
        }

        return ans;
    }
};