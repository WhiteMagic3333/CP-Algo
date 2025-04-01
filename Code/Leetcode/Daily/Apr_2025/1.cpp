class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long cur = questions[i][0];
            if (questions[i][1] + i + 1 < n) {
                cur += dp[questions[i][1] + i + 1];
            }
            dp[i] = max(dp[i + 1], cur);
        }
        return dp[0];
    }
};