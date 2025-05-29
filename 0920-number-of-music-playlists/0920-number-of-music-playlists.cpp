class Solution {
public:
    int n, goal, k;
    long long dp[101][101];
    const int MOD = 1e9 + 7;

    long long solve(int currSong, int usedSongs) {
        if (currSong == goal)
            return usedSongs == n ? 1 : 0;

        if (dp[currSong][usedSongs] != -1)
            return dp[currSong][usedSongs];

        long long res = 0;
        res += (n - usedSongs) * solve(currSong + 1, usedSongs + 1) % MOD;

        if (usedSongs > k)
            res += (usedSongs - k) * solve(currSong + 1, usedSongs) % MOD;

        return dp[currSong][usedSongs] = res % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        this->n = n;
        this->goal = goal;
        this->k = k;

        memset(dp, -1, sizeof(dp));
        return (int)solve(0, 0);
    }
};
