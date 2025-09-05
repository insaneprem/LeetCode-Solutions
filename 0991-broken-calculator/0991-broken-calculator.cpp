class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue >= target)
            return startValue - target;

        int steps = 0;
        while (target > startValue) {
            steps++;
            if (target % 2 == 0)
                target /= 2;
            else
                target++;
        }

        if (target == startValue)
            return steps;

        return (startValue - target + steps);
    }
};