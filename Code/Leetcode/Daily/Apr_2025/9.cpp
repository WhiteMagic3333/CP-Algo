class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        bitset<101> vis;
        int ans = 0;
        for (int i : arr) {
            if (i < k) {
                return -1;
            } else if (i > k) {
                ans += !vis[i];
                vis[i] = true;
            }
        }
        return ans;
    }
};