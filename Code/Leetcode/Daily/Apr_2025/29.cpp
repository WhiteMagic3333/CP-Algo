class Solution {
public:
    long long countSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), mx = *max_element(arr.begin(), arr.end());
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (arr[i] == mx) {
                idx.push_back(i);
            }
        }
        long long ans = 0, rem = idx.size();
        if (rem >= k) {
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (i > idx[j]) {
                    j++;
                    rem--;
                    if (rem < k) {
                        break;
                    }
                }
                ans += n - idx[j + k - 1];
            }
        }
        return ans;
    }
};