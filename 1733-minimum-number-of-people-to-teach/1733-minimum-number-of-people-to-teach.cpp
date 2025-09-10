class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size(); 

        vector<unordered_set<int>> knows(m + 1);
        for (int i = 0; i < m; i++) {
            for (auto lang : languages[i]) {
                knows[i + 1].insert(lang);
            }
        }

        unordered_set<int> badPeople;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (auto lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                badPeople.insert(u);
                badPeople.insert(v);
            }
        }

        if (badPeople.empty()) return 0;

        
        vector<int> freq(n + 1, 0);
        for (auto person : badPeople) {
            for (auto lang : knows[person]) {
                freq[lang]++;
            }
        }

       
        int best = *max_element(freq.begin(), freq.end());
        return (int)badPeople.size() - best;
    }
};
