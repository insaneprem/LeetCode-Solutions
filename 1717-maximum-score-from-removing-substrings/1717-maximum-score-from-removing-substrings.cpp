class Solution {
public:
    int ans = 0;
    string solve(string str, string pattern, int val) {
        stack<char> st;

        for (auto i : str) {
            if (!st.empty() && st.top() == pattern[0] && i == pattern[1]) {
                ans += val;
                st.pop();
            } else {
                st.push(i);
            }
        }

        string temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        string first = "ab", second = "ba";
        if (y > x) {
            swap(first, second);
            swap(x, y);
        }

        string temp = solve(s, first, x);
        solve(temp, second, y);

        return ans;
    }
};