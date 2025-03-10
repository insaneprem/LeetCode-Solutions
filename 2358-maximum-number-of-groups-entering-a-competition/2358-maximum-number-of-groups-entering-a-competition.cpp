class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int groups = 0;
        int used = 0;

        while (used + (groups + 1) <= n) {
            groups++;
            used += groups;
        }
        return groups;
    }
};
