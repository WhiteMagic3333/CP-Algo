class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        vector<bool> p(1e4 + 1, true);
        long long sum = 0, count = 0;
        for (int i = 0; i < banned.size(); i++) {
            p[banned[i]] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (p[i]) {
                sum += i;
                if (sum > maxSum) {
                    break;
                }
                count++;
            }
        }
        return count;
    }
};