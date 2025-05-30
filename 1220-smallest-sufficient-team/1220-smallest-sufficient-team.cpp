class Solution {
public:
    int n, m;
    unordered_map<string, int> skill_idx, dp;
    vector<int> people_skill, result;
    void solve(int idx, int mask, vector<int> temp) {
        if (idx == m) {
            if (mask == ((1 << n) - 1)) {
                if (result.size() == 0 || result.size() >= temp.size())
                    result = temp;
            }
            return;
        }

        if (result.size() != 0 && result.size() <= temp.size())
            return;

        string key = to_string(idx) + " " + to_string(mask);
        if (dp.find(key) != dp.end()) {
            if (dp[key] <= temp.size())
                return;
        }
        solve(idx + 1, mask, temp);

        if (mask | people_skill[idx] != mask) {

            temp.push_back(idx);
            solve(idx + 1, mask | people_skill[idx], temp);
            temp.pop_back();
            dp[key] = temp.size();
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        this->n = req_skills.size();
        this->m = people.size();
        skill_idx.clear();
        people_skill.clear();
        result.clear();
        dp.clear();

        for (int i = 0; i < n; i++) {
            skill_idx[req_skills[i]] = i;
        }

        for (auto& v : people) {
            int cs = 0;
            for (auto skill : v) {
                cs |= (1 << skill_idx[skill]);
            }
            people_skill.push_back(cs);
        }

        
        solve(0, 0, {});

        return result;
    }
};