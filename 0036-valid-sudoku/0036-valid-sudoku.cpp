class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0'; 
                int boxIndex = (i / 3) * 3 + (j / 3);

                if ((row[i] & (1<<num)) || (col[j] & (1<<num)) || (box[boxIndex] & (1<<num))) {
                    return false; 
                }

                row[i] |= (1<<num);
                col[j] |= (1<<num);
                box[boxIndex] |= (1<<num);
            }
        }

        return true;
    }
};
