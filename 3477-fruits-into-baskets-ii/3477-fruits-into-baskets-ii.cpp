class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), unplace = n;

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            int fruit = fruits[i];
            for (int j = 0; j < n; j++) {
                if (!visited[j] && fruit <= baskets[j]) {
                    visited[j] = 1;
                    unplace--;
                    break;
                }
            }
        }

        return unplace;
    }
};