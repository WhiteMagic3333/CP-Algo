class Solution {
public:
    //tough day
    long long countInterestingSubarrays(vector<int>& arr, int mod, int k) {
        unordered_map<int, int> m;
        long long ans = 0;
        int n = arr.size(), pre = 0;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            pre += ((arr[i] % mod) == k);
            ans += m[(pre - k + mod) % mod];
            m[pre % mod]++;
        }
        return ans;
    }
};