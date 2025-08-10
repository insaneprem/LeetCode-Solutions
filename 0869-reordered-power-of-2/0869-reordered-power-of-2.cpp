class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string> st;
        st.insert("1");

        for (int i = 2; i <= 1e9; i = i * 2) {
            string str = to_string(i);
            st.insert(str);
        }

        string to_match = to_string(n);
        ranges::sort(to_match);

        do {
            if (st.count(to_match))
                return true;

        } while (next_permutation(begin(to_match), end(to_match)));

        return false;
    }
};