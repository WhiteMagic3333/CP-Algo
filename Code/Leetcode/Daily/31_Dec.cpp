class Solution {
public:
    long long DP(vector<long long> &dp, int i) {
        if (i < 0) {
            return 0LL;
        }
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp[i] = min(dp[i - 1] + cost[0], dp[i - 7] + cost[1], dp[i - 30] + cost[2]
        int last_day = days.back(), j = 0;
        vector<long long> dp(last_day + 1, 0);
        for (int i = 1; i <= last_day; i++) {
            if (i == days[j]) {
                //dp
                dp[i] = min({
                    DP(dp, i - 1) + costs[0],
                    DP(dp, i - 7) + costs[1],
                    DP(dp, i - 30) + costs[2],
                });
                j++;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};