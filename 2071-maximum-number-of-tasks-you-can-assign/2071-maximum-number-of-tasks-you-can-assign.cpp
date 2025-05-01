class Solution {
public:
    bool solve(vector<int>& t, vector<int>& w, int pills, int strength, int m) {
        multiset<int> st;
        for (auto it : w)
            st.insert(it);
        
        for (int i = m - 1; i >= 0; --i) {
            auto val = st.lower_bound(t[i]);
            if (val != st.end()) {
                st.erase(val);
            } else {
                if (pills > 0) {
                    val = st.lower_bound(t[i] - strength);
                    if (val != st.end()) {
                        st.erase(val);
                        --pills;
                    } else
                        return false;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int pills, int strength) {
        sort(t.begin(), t.end());
        sort(w.begin(), w.end());
        int ans = 0, s = 1, e = min(t.size(), w.size());
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (solve(t, w, pills, strength, m))
                ans = m, s = m + 1;
            else
                e = m - 1;
        }
        return ans;
    }
};