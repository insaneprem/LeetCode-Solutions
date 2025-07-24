class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string, string>> groups;

        for (auto& word : words) {
            string even = "", odd = "";

            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0)
                    even += word[i];
                else
                    odd += word[i];
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());

            groups.insert({even, odd});
        }

        return groups.size();
    }
};
