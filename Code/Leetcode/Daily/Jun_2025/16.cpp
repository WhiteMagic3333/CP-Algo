class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int mn = arr[0], ans = -1, n = arr.size();
        for (int i = 1; i < n; i++) {
            if (mn < arr[i]) {
                ans = max(ans, arr[i] - mn);
            }
            mn = min(mn, arr[i]);
        }
        return ans;
    }
};