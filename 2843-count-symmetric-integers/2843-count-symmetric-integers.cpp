class Solution {
public:
    bool issymertirc(int n) {
        string num = to_string(n);
        int len = num.size();

        if (len % 2 == 1)
            return false;

        int right = 0, left = 0;

        for (int i = 0; i < len; i++) {
            int digit = num[i] - '0';
            if (i < len / 2)
                left += digit;
            else
                right += digit;
        }

        return left == right;
    }
    int countSymmetricIntegers(int low, int high) {
        int result = 0;

        while (low <= high)
            result += issymertirc(low), low++;
        return result;
    }
};