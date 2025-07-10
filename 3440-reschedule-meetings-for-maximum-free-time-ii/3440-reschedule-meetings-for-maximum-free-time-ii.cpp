class Solution {
public:
    int maxFreeTime(int n, vector<int>& start, vector<int>& end) {
        map<int, int> mpp;
        mpp[start[0]]++;
        mpp[n - end.back()]++;
        
        for (int i = 1; i < start.size(); i++) {
            mpp[start[i] - end[i - 1]]++;
        }

        int ans = max(start[1] - (end[0] - start[0]), n - end[start.size() - 2] - (end.back() - start.back()));

        for (int i = 0; i < start.size(); i++) {
            if (i > 0 && i < start.size() - 1) {
                ans = max(ans, start[i + 1] - end[i - 1] - (end[i] - start[i]));
            }

            int left = (i == 0) ? start[0] : (start[i] - end[i - 1]);
            int right = (i == start.size() - 1) ? (n - end.back()) : (start[i + 1] - end[i]);

            mpp[left]--;
            mpp[right]--;

            if (mpp[left] == 0) mpp.erase(left);
            if (mpp[right] == 0) mpp.erase(right);

            if (mpp.rbegin()->first >= (end[i] - start[i])) {
                int currentFreeTime;
                if (i == 0) currentFreeTime = start[i + 1];
                else if (i == start.size() - 1) currentFreeTime = n - end[i - 1];
                else currentFreeTime = start[i + 1] - end[i - 1];

                ans = max(ans, currentFreeTime);
            }

            mpp[left]++;
            mpp[right]++;
        }

        return ans;
    }
};
