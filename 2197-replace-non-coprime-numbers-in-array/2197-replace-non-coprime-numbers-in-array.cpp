class Solution {
public:
    vector<int> getans(stack<int>& st) {
        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for(auto v:nums){
            int num = v;

            while(!st.empty() && gcd(st.top(),num)>1){
                int lc = lcm(st.top(),num);
                st.pop();
                num = lc;
            }

            st.push(num);
        }

        return getans(st);
    }
};