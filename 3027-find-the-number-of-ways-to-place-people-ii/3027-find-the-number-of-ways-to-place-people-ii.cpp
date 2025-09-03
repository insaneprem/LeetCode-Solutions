class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        for (int i = 0; i < points.size() - 1; i++) {
            const auto& pointA = points[i];
            int xMin = pointA[0] - 1, xMax = INT_MAX, yMin = INT_MIN,
                yMax = pointA[1] + 1;

            for (int j = i + 1; j < points.size(); j++) {
                const auto& pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                    pointB[1] < yMax) {
                    ans++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
            }
        }
        return ans;
    }
};