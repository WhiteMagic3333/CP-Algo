class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pre_sum2(n + 1, 0);
        vector<long long> suf_sum1(n + 2, 0);
        for (int i = 0; i < n; i++) {
            pre_sum2[i + 1] = pre_sum2[i] + grid[1][i];
            suf_sum1[n - i] = suf_sum1[n - i + 1] + grid[0][n - i - 1];
        }
        long long ans = 1e15;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, max(pre_sum2[i - 1], suf_sum1[i + 1]));
        }
        return ans;
    }
};