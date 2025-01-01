class Solution {
public:
    long long fun(vector<vector<long long>> &dp, int i, int j) {
        if (i < 0) {
            return 0LL;
        } else if (j < 0) {
            return 1LL;
        }
        return dp[i][j];
    }

    int numWays(vector<string>& words, string target) {
        // dynamic programming intuition
        // let dp[i][j] = number of ways to create 
        // string (target[0] .. target[j]) using atmost i'th max char
        long long mod = 1e9 + 7;
        vector<vector<long long>> freq(1000, vector<long long> (27, 0));
        for (auto word : words) {
            for (int i = 0; i < word.length(); i++) {
                freq[i][word[i] - 'a']++;
            }
        }
        int n = target.length();
        vector<vector<long long>> dp(1000, vector<long long> (1000, 0));
        dp[0][0] = freq[0][target[0] - 'a'];
        int m = words.front().length();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (j < n) {
                    dp[i][j] = (fun(dp, i - 1, j - 1) * freq[i][target[j] - 'a']) % mod;
                }
                dp[i][j] += fun(dp, i - 1, j);
                dp[i][j] %= mod;
            }
        }
        return dp[m - 1][n - 1];
    }
};