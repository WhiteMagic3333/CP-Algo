class Solution {
public:
    vector<int> maxSubsequence(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> order(n, 0), rev_order(n, 0), ans; //order[i] -> idx of element at i'th position in sorted
        //rev_order[i] -> idx of arr[i] in the sorted array
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&] (int i, int j) {
            return arr[i] > arr[j];
        });
        for (int i = 0; i < n; i++) {
            rev_order[order[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (rev_order[i] < k) {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};