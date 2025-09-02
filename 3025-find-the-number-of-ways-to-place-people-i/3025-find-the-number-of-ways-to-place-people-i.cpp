class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int brx = points[i][0], bry = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int tlx = points[j][0], tly = points[j][1];
                if (tlx <= brx && tly >= bry) {
                    bool flag = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j)
                            continue;
                        int crx = points[k][0], cry = points[k][1];

                        if ((crx >= tlx && crx <= brx) &&
                            (cry >= bry && cry <= tly)) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};