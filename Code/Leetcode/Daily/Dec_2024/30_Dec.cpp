class Solution {
public:

    long long fun(vector<long long> &dp, int i) {
        if (i < 0) {
            return 0LL;
        }
        return dp[i];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(1e6, 0);
        dp[0] = 1;
        long long mod = 1e9 + 7;
        for (int i = 0; i <= high; i++) {
            dp[i] += fun(dp, i - zero) % mod;
            dp[i] %= mod;
            dp[i] += fun(dp, i - one) % mod;
            dp[i] %= mod;
        }
        long long ans = 0;
        for (int i = low; i <= high; i++) {
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};