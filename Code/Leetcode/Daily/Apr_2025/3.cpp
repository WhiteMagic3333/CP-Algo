class Solution {
public://thodi toh mehnat karlo leetcode vaalo
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, n = nums.size(), left = 0, pre_max = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left * nums[i]);
            left = max(left, pre_max - nums[i]);
            pre_max = max(pre_max, (long long)nums[i]);
        }
        return ans;
    }
};