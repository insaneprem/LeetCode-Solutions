class Solution {
public:
    int smallestNumber(int n) {
        bool isset = false;
        for (int i = 16; i >= 0; i--) {
            bool set = n & (1 << i);
            isset |= set;
            if (isset)
                n |= (1 << i);
        }

        return n;
    }
};