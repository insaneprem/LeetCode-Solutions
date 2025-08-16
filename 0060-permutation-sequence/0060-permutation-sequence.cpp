class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; i++)
            str += char(i + '0');

        do {
            k--;
            if (k == 0)
                return str;
            
        } while (next_permutation(begin(str), end(str)));
        return str;
    }
};