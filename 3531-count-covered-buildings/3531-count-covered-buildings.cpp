class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> row, col;
        for (auto& b : buildings) {
            row[b[0]].insert(b[1]);
            col[b[1]].insert(b[0]);
        }
        
        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (*row[x].begin() < y && *row[x].rbegin() > y &&
                *col[y].begin() < x && *col[y].rbegin() > x)
                ans++;
        }
        return ans;
    }
};
