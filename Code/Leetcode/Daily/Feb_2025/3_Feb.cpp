class Solution {
public:

    void check(int &ans, vector<int> &nums) {
        int cur = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            ans = max(ans, cur);
        }
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        check(ans, nums);
        reverse(nums.begin(), nums.end());
        check(ans, nums);
        return ans;
    }
};