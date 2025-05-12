class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                for (int k = 0; k < n; k++) {
                    if (k == j || k == i) continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0 && (num >= 100 && num <= 999)) st.insert(num);
                }
            }
        }

        vector<int> result(begin(st), end(st));
        return result;
    }
};