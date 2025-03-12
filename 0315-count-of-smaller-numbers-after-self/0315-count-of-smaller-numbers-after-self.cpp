#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //less_equal(multiset )
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds os;

        int n=nums.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            os.insert(nums[i]);
            ans[i]=os.order_of_key(nums[i]);
        }

        return ans;
    }
};