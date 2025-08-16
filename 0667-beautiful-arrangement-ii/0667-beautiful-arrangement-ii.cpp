class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int currdiff = n - 1;

        vector<int> ans;
        ans.push_back(1);
        for (int i = 1; i < n; i++) {
            k--;
            if (k > 0) {
                if (i & 1) {
                    ans.push_back(ans.back() + currdiff);
                } else {
                    ans.push_back(ans.back() - currdiff);
                }
                currdiff--;
            } else {
                if (i & 1) {
                    while (ans.size() < n)
                        ans.push_back(ans.back() + 1);
                } else {
                    while (ans.size() < n)
                        ans.push_back(ans.back() - 1);
                }
                break;
            }
        }

        return ans;
    }
};