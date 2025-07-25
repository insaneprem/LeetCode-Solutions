class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n == 1 || n == 2)
            return false;

        for (int i = 0; i < n - 2; i++) {
            if ((arr[i] & 1) && (arr[i + 1] & 1) && (arr[i + 2] & 1))
                return true;
        }
        
        return false;
    }
};