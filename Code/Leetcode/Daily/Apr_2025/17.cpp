class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (((i * j) % k == 0) && arr[i] == arr[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};