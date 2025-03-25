class Solution {
public:
    bool check(vector<vector<int>>& rectangles, int dim) {
        int gapcnt = 0;

        sort(begin(rectangles), end(rectangles), [&](auto & a, auto & b) { return a[dim] < b[dim]; });

        int end = rectangles[0][dim + 2];

        for (int i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            if (end <= rect[dim]) gapcnt++;
            
            end = max(end, rect[dim + 2]);
        }

        return gapcnt >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles, 0) || check(rectangles, 1);
    }
};