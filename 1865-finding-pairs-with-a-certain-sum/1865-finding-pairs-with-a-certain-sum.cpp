class FindSumPairs {
public:
    map<int, int> freq;
    vector<int> nums1, nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto it : nums2)
            freq[it]++;
    }

    void add(int index, int val) {
        int num = nums2[index];
        freq[num]--;
        if (freq[num] == 0)
            freq.erase(num);
        freq[num + val]++;
        nums2[index] += val;
    }

    int count(int tot) {
        int ans = 0;
        for (auto it : nums1) {
            int rem = tot - it;
            ans += freq[rem];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */