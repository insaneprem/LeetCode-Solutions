class Solution {
public:
    int possibleStringCount(string word) {
        stack<int> st;
        int ans = 0;

        for (auto ch : word) {
            if (!st.empty() && st.top() == ch)
                ans++;
            st.push(ch);
        }

        return ans + 1;
    }
};