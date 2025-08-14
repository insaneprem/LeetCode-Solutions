class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();

        for (int i = 1; i + 1 < n; i++) {
            if ((num[i] == num[i - 1] && num[i] == num[i + 1])) {
                if (ans == "")
                    ans = string(3, num[i]);
                else if (num[i] > ans[0])
                    ans = string(3, num[i]);
            }
        }

        return ans;
    }
};