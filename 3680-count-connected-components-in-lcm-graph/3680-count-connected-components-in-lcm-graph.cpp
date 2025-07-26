class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findpar(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findpar(parent[node]); // path compession
    }

    void unionSize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int CompCount = 0;
        ranges::sort(nums);

        while (!nums.empty() && nums.back() > threshold) {
            CompCount++;
            nums.pop_back();
        }

        if (nums.empty()) return CompCount;

        int n = nums.size();
        DSU dsu(n);
        unordered_map<int, int> divisorMap;

        for (int i = 0; i < n; i++) {
            for (int divisor = 1; divisor * divisor <= nums[i]; divisor++) {
                if (nums[i] % divisor == 0) {
                    if (divisorMap.count(divisor)) {
                        int otherIdx = divisorMap[divisor];
                        if (lcm(nums[i], nums[otherIdx]) <= threshold) {
                            dsu.unionSize(i, otherIdx);
                        }
                    } else {
                        divisorMap[divisor] = i;
                    }

                    int quotient = nums[i] / divisor;
                    if (quotient != divisor) {
                        if (divisorMap.count(quotient)) {
                            int otherIdx = divisorMap[quotient];
                            if (lcm(nums[i], nums[otherIdx]) <= threshold) {
                                dsu.unionSize(i, otherIdx);
                            }
                        } else {
                            divisorMap[quotient] = i;
                        }
                    }
                }
            }
        }

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(dsu.findpar(i));
        }

        return CompCount + st.size();
    }
};