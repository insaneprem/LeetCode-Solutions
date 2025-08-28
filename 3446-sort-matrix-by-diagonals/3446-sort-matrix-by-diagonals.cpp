class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto isValid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        
        for (int r = n - 1; r >= 0; r--) {
            int i = r, j = 0;
            
            vector<int> vec;
            while(isValid(i,j)){
               vec.push_back(grid[i][j]);
               i++;
               j++;
            }

            sort(rbegin(vec),rend(vec));
            i = r, j = 0;
            int idx = 0;
            while(isValid(i,j)){
               grid[i][j] = vec[idx++];
               i++;
               j++;
            }
        }

        for (int c = 1; c < m; c++) {
            int i = 0, j = c;
            
            vector<int> vec;
            while(isValid(i,j)){
               vec.push_back(grid[i][j]);
               i++;
               j++;
            }

            ranges::sort(vec);
            i = 0, j = c;
            int idx = 0;
            while(isValid(i,j)){
               grid[i][j] = vec[idx++];
               i++;
               j++;
            }
        }

        

        return grid;
    }
};