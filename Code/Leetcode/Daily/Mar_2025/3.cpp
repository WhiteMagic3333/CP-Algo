class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        int n = arr.size(), idx = 0;
        vector<int> ans(n, 0);
        int eq = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < pivot) {
                ans[idx++] = arr[i];
            } else if (arr[i] == pivot) {
                eq++;
            }
        }
        while (eq--) {
            ans[idx++] = idx;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > pivot) {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};