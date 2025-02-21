class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<int, int> mpp;

        for (auto i : nums) mpp[stoi(i, nullptr, 2)]++;

        int len = nums[0].size();
        
        for (int i = 0; i < (1 << len); i++) {
            if (mpp[i] == 0) {
                bitset<32> binary(i);
                return binary.to_string().substr(32 - len);
            }
        }


        return "";
    }
};