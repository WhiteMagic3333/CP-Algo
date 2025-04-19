class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if ((2 * arr[i]) > upper) {
                break;
            }
            int l = lower_bound(arr.begin() + i + 1, arr.end(), lower - arr[i]) - arr.begin();
            int r = lower_bound(arr.begin() + i + 1, arr.end(), upper - arr[i] + 1) - arr.begin();
            ans += max(0, r - l);
        }
        return ans;
    }
};