int countArrays(vector<int> required_sums) {
    int n = required_sums.size();
    const int MOD = 1e9 + 7;
    const int MAX_VAL = 5000;

    vector<int> digit_sums(MAX_VAL + 1, 0);
    for (int i = 0; i <= MAX_VAL; ++i) {
        int temp = i;
        int s = 0;
        while (temp > 0) {
            s += temp % 10;
            temp /= 10;
        }
        digit_sums[i] = s;
    }

    vector<long long> dp(MAX_VAL + 2, 0);

    int last_target = required_sums[n - 1];
    for (int v = MAX_VAL; v >= 0; --v) {
        dp[v] = dp[v + 1]; // Suffix sum logic
        if (digit_sums[v] == last_target) {
            dp[v] = (dp[v] + 1) % MOD;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        int target = required_sums[i];
        vector<long long> next_dp(MAX_VAL + 2, 0);

        for (int v = MAX_VAL; v >= 0; --v) {
            next_dp[v] = next_dp[v + 1]; // Maintain suffix sum
            
            if (digit_sums[v] == target) {
                next_dp[v] = (next_dp[v] + dp[v]) % MOD;
            }
        }
        dp = next_dp;
    }

    return (int)dp[0];
}