class Solution {
public:
    int count(vector<int> &nums, int i, int rem) {
        if (i == -1) {
            if (rem == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        return count(nums, i - 1, rem + nums[i]) + count(nums, i - 1, rem - nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // 2^20 is nearly 10^5 hence recursion will work
        //can also use dp
        int n = nums.size();
        return count(nums, n - 1, target);
    }
};