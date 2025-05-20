class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (nums[i] > cur) {
                return false;
            }
        }
        return true;
    }
};