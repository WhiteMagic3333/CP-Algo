class Solution {
public:
    typedef long long ll;
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        int n = dif.size() + 1;
        vector<ll> arr(n, 0);
        ll mn = 0, mx = 0;
        for (int i = 0; i < n - 1; i++) {
            arr[i + 1] = arr[i] + dif[i];
            mn = min(arr[i + 1], mn);
            mx = max(arr[i + 1], mx);
        }
        ll add = 0;
        add = lower - mn;
        mx = mx + add;
        return max(0, (int)(upper - mx) + 1);
    }
};