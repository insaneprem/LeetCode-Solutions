#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds; // less_equal(multiset )
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;

        pbds st;
        vector<int> mpp(n);
        for (int i = 0; i < n; i++)
            mpp[nums2[i]] = i;

        for (int i = 0; i < n; i++) {
            int idx = mpp[nums1[i]];

            int left = st.order_of_key(idx);
            int right = (n - 1 - idx) - (st.size() - left);

            ans += (long long)((long long) left * (long long)right);
            st.insert(idx);
        }

        return ans;
    }
};