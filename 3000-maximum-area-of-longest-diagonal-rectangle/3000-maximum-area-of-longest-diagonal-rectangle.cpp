class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int sqmaxDiagonal = 0, ans = 0;

        for (auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diagonalLen = l * l + w * w;

            if (diagonalLen > sqmaxDiagonal) {
                sqmaxDiagonal = diagonalLen;
                ans = l * w; 
            } else if (diagonalLen == sqmaxDiagonal) {
                ans = max(ans, l * w);
            }
        }

        return ans;
    }
};