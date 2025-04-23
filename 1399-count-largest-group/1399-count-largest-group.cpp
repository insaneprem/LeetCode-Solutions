class Solution {
public:
    static int digitsum(int n) {
        int val = 0;
        while (n) val += n % 10, n /= 10;
        return val;
    }
    int countLargestGroup(int n) {
        vector<int> size(37,0);

        for (int i = 1; i <= n; i++) size[digitsum(i)]++;
        
        return count(begin(size), end(size), *max_element(begin(size), end(size)));
    }
};