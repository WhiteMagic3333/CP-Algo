class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return arr;
        }
        sort(arr.begin(), arr.end());
        //1 2 5 8
        //1 2 2 3
        vector<int> subset_size(n, 1);
        int mx_i = -1, mx = -1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    subset_size[i] = max(subset_size[i], subset_size[j] + 1);
                }
            }
            if (subset_size[i] > mx) {
                mx = subset_size[i];
                mx_i = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[mx_i]);
        for (int j = mx_i - 1; j >= 0; j--) {
            if (arr[mx_i] % arr[j] == 0 && subset_size[j] == mx - 1) {
                ans.push_back(arr[j]);
                mx--;
                mx_i = j;
            }
        }
        return ans;
    }
};