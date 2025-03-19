class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fact;

        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                fact.push_back(i);
                if(n/i != i) fact.push_back(n/i);
            }
        }

        ranges::sort(fact);

        return fact.size()<k ? -1 : fact[k-1];
    }
};