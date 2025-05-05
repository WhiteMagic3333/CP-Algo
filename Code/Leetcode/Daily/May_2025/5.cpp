class Solution {
public:
    int numTilings(int n) {
        // with three states its better to visualize the tiles
        // where dp[i][0] means covering all tiles till i - 1 and
        // covering the first tile
        // where as dp[i][1] means 2nd tile covered along with all i - 1
        // and at dp[i][2] all tiles are covered till i
        vector<array<long long, 3>> dp(n + 1); //better
        dp[1] = dp[0] = {0, 0, 1}; //
        long long mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            //using 2 X 1 dominos
            //horizontally
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = dp[i - 2][2];
            //vertically
            dp[i][2] += dp[i - 1][2];
            //using triangle dominos
            dp[i][0] += dp[i - 2][2];
            dp[i][1] += dp[i - 2][2];
            dp[i][2] += dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] %= mod;
            dp[i][1] %= mod;
            dp[i][2] %= mod;
        }
        return dp[n][2];
    }
};