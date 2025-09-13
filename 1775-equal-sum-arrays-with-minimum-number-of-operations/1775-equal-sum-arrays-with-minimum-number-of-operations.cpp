class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = accumulate(begin(nums1), end(nums1), 0);
        int n2 = accumulate(begin(nums2), end(nums2), 0);

        priority_queue<int> pq;
        if (n1 == n2)
            return 0;
        if (n1 < n2){
            swap(n1,n2);
            swap(nums1, nums2);
        }
        for (auto i : nums1)
            pq.push(i - 1);
        for (auto i : nums2)
            pq.push(6 - i);
        

        int op = 0;
        int diff = n1 - n2;
        while (!pq.empty()) {
            int val = pq.top();
            pq.pop();

            diff -= val;
            op++;
            if (diff <= 0)
                break;
        }

        return diff <= 0 ? op : -1;
    }
};