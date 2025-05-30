class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int step = 0;
        while (target > startValue) {
            step++;
            if (target % 2 == 0)
                target /= 2;
            else
                target++;
        }

        return step + startValue - target;
    }
};