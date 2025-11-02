class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,1));
        for(auto it:walls){
            grid[it[0]][it[1]]=0;
        }
        for(auto it:guards){
            grid[it[0]][it[1]]=0;
        }
        int cnt=0;
        for(auto it:guards){
            int row=it[0],col=it[1];
            for(int i=col+1;i<n;i++){
                if(grid[row][i]==0)break;
                else if(grid[row][i]==1){
                    grid[row][i]=2;cnt++;
                }
            }
            for(int i=col-1;i>=0;i--){
                if(grid[row][i]==0)break;
                else if(grid[row][i]==1){
                    grid[row][i]=2;cnt++;
                }
            }
            for(int i=row+1;i<m;i++){
                if(grid[i][col]==0)break;
                else if(grid[i][col]==1){
                    grid[i][col]=2;cnt++;
                }
            }
            for(int i=row-1;i>=0;i--){
                if(grid[i][col]==0)break;
                else if(grid[i][col]==1){
                    grid[i][col]=2;cnt++;
                }
            }
        }
        return m*n-cnt-guards.size()-walls.size();
    }

};