class Solution {
public:
    vector<int> findusers(string& str) {
        vector<int> users;

        stringstream ss(str);
        string token;

        while (ss >> token) {
            int v = stoi(token.substr(2));
            users.push_back(v);
        }

        return users;
    }
    void markall(vector<int>& ans) {
        for (auto& i : ans)
            i += 1;
    }
    void markonline(vector<int>& lastoffline, vector<int>& ans, int time) {
        int n = ans.size();

        for (int i = 0; i < n; i++) {
            if (time - lastoffline[i] >= 60) {
                ans[i]++;
            }
        }
    }
    void markusers(vector<int>& user, vector<int>& ans) {
        for (auto& i : user)
            ans[i]++;
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        // message -> time -> offline first
        // messge idi -> i++;
        // offline -> of[i] = -1 -> time
        // all -> ++
        // here -> iterate -> curtime - time > 1

        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            int atime = stoi(a[1]);
            int btime = stoi(b[1]);

            if (atime != btime)
                return atime < btime;

            bool astatus = a[0] == "OFFLINE";
            bool bstatus = b[0] == "OFFLINE";

            if (astatus != bstatus)
                return astatus;

            return a[0] < b[0];
        });

        for (auto i : events) {
            cout << "{ " << i[0] << " " << i[1] << " " << i[2] << " }\n";
        }

        vector<int> lastoffline(n, -60);

        vector<int> ans(n, 0);

        for (auto i : events) {
            string type = i[0];
            int time = stoi(i[1]);
            if (type == "OFFLINE") {
                lastoffline[stoi(i[2])] = time;
            } else {
                string temp = i[2];
                if (temp == "ALL") {
                    markall(ans);
                } else if (temp == "HERE") {
                    markonline(lastoffline, ans, time);
                } else {
                    vector<int> users = findusers(i[2]);
                    markusers(users, ans);
                }
            }
        }
        return ans;
    }
};