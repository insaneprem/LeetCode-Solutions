class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto w:operations){
            if(w[1] == '+') ans++;
            else ans--;
        }

        return ans;
    }
};