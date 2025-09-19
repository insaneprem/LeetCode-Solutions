class Spreadsheet {
public:
    bool isnum(char ch) { return ch >= '0' && ch <= '9'; }
    vector<vector<int>> grid;
    Spreadsheet(int rows) { grid.assign(rows + 1, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';

        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';

        grid[row][col] = 0;
    }

    int getValue(string formula) {
        string left = "", right = "";
        bool seen = false;

        for (auto c : formula) {
            if (c == '=')
                continue;
            if (c == '+') {
                seen = true;
                continue;
            }
            if (!seen)
                left += c;
            else
                right += c;
        }

        cout << left << " " << right << " ";
        int l = (isnum(left[0])) ? stoi(left) : -1;
        int r = (isnum(right[0])) ? stoi(right) : -1;
        cout << l << " " << r;
        if (l == -1) {
            int row = stoi(left.substr(1));
            int col = left[0] - 'A';

            l = grid[row][col];
        }

        if (r == -1) {
            int row = stoi(right.substr(1));
            int col = right[0] - 'A';

            r = grid[row][col];
        }

        return l + r;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */