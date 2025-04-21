class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // 3 -1 4 5 3
        long sum = 0, maxi = 0, mini = 0;
        for (auto d: differences) {
            sum += d;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }

        return max(0L, (upper - lower) - (maxi - mini) + 1);
    }
};