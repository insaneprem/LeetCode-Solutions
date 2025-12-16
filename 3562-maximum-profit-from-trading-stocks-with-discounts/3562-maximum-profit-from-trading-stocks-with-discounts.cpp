const int INF = 1e9;
vector<vector<int>> tree;
vector<vector<vector<int>>> dp;
vector<int> presP, futP;
int Bud;

void dfs(int u) {
    for (auto v : tree[u]) dfs(v);

    for (int parBuy = 0; parBuy <= 1; parBuy++) {
        vector<int> nobuy(Bud+1, -INF), buy(Bud+1, -INF);
        nobuy[0] = 0;

        int cost = presP[u] / (parBuy ? 2 : 1);
        int profit = futP[u] - cost;
        if (cost <= Bud) buy[cost] = profit;

        for (auto v : tree[u]) {
            vector<int> temp(Bud+1, -INF);
            for (int i = 0; i <= Bud; i++) {
                if (nobuy[i] >= -INF/2){
                    for (int j = 0; i + j <= Bud; j++){
                        temp[i + j] = max(temp[i + j], nobuy[i] + dp[v][0][j]);
                    }
                }
            }
            swap(nobuy, temp);

            temp.assign(Bud+1, -INF);
            for (int i = 0; i <= Bud; i++) {
                if (buy[i] >= -INF/2){
                    for (int j = 0; i + j <= Bud; j++){
                        temp[i + j] = max(temp[i + j], buy[i] + dp[v][1][j]);
                    }
                }
            }
            swap(buy, temp);
        }

        dp[u][parBuy].resize(Bud+1);
        for (int i = 0; i <= Bud; i++) dp[u][parBuy][i] = max(nobuy[i], buy[i]);
    }
}

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        presP = present; futP = future; Bud = budget;
        tree.assign(n, {});
        dp.assign(n, vector<vector<int>>(2, vector<int>(Bud+1, -INF)));

        for (auto& e : hierarchy)
            tree[e[0]-1].push_back(e[1]-1);

        dfs(0);
        return *max_element(dp[0][0].begin(), dp[0][0].end());
    }
};
