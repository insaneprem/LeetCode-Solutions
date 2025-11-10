class BIT {
    vector<int> tree;
public:
    BIT(int n) : tree(n + 1) {}
    void add(int i) { for (++i; i < tree.size(); i += i & -i) tree[i]++; }
    int sum(int i) { int res = 0; for (++i; i; i -= i & -i) res += tree[i]; return res; }
    int range(int l, int r) { return l > r ? 0 : sum(r) - sum(l - 1); }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end()), ans = 0;
        vector<vector<int>> pos(mx + 1);
        for (int i = 0; i < n; i++) pos[nums[i]].push_back(i);
        BIT bit(n);
        for (int i = 0; i < n; i++) if (nums[i] == 0) bit.add(i);
        for (int v = 1; v <= mx; v++) {
            int last = -2;
            for (auto i : pos[v]) {
                if (last == -2 || bit.range(last + 1, i - 1)) ans++;
                last = i;
                bit.add(i);
            }
        }
        return ans;
    }
};
