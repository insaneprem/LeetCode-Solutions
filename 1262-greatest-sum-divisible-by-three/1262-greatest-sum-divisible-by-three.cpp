class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        pair<int, int> one = {1e9, 1e9}, two = {1e9, 1e9};

        int totalsum = 0;
        for (auto& i : nums) {
            totalsum += i;
            if (i % 3 == 1) {
                if (i < one.first) {
                    one.second = one.first;
                    one.first = i;
                } else if (i < one.second)
                    one.second = i;
            } else if (i % 3 == 2) {
                if (i < two.first) {
                    two.second = two.first;
                    two.first = i;
                } else if (i < two.second)
                    two.second = i;
            }
        }

        // cout << one << " " << two;

        if (totalsum % 3 == 0)
            return totalsum;

        if (totalsum % 3 == 1) {
            int tosub = 1e9;

            if (one.first != 1e9)
                tosub = one.first;
            if (two.first != 1e9 && two.second != 1e9)
                tosub = min(tosub, two.first + two.second);

            return totalsum - tosub;
        }

        int tosub = 1e9;

        if (two.first != 1e9)
            tosub = two.first;
        if (one.first != 1e9 && one.second != 1e9)
            tosub = min(tosub, one.first + one.second);

        return totalsum - tosub;
    }
};