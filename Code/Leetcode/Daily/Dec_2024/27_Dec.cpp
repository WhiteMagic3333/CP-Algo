class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        // we can sub j from each element
        // hence a[j] = a[j] - j
        // find the max from the right for each element
        // mx[j] = max(a[j], a[j + 1] ...) from modified array
        // iterate for each i, and
        // ans = max(ans, a[i] + 2 * i + mx[i]), adding extra i cause i was removed earlier as j
        int n = a.size();
        for (int j = 0; j < n; j++) {
            a[j] = a[j] - j;
        }
        vector<int> ga(n); //greatest after i (excluding i)
        // vector<int> gf(n + 1, 0); //greatest from i (including i)
        ga[n - 1] = -n;
        for (int i = n - 2; i >= 0; i--) {
            ga[i] = max(a[i + 1], ga[i + 1]);
        }
        int ans = a[0];
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, a[i] + 2 * i + ga[i]);
        }
        return ans;
    }
};