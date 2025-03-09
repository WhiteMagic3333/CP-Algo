class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        int ans = 0, last = -2, n = arr.size();
        for (int i = 1; i < n + k - 1; i++) {
            if (arr[(i + n) % n] == arr[(i - 1 + n) % n]) {
                last = i - 1;
            }
            if (i > k - 2) {
                if (last <= (i - k)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};