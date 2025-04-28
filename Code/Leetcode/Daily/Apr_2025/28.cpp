class Solution {
public:
    long long _range_sum(vector<long long> &p_sum, int i, int j) {
        long long size = j - i + 1;
        long long sum = p_sum[j];
        if (i > 0) {
            sum -= p_sum[i - 1];
        }
        return sum * size;
    }

    long long countSubarrays(vector<int>& arr, long long k) {
        int n = arr.size();
        vector<long long> prefix_sum(n, 0);
        prefix_sum[0] = arr[0];
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = arr[i] + prefix_sum[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int low = i, high = n - 1, first = i - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (_range_sum(prefix_sum, i, mid) < k) {
                    low = mid + 1;
                    first = max(first, mid);
                } else {
                    high = mid - 1;
                }
            }
            ans += first - i + 1;
        }
        return ans;
    }
};