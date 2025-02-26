class Solution {
public:
    int kadane(vector<int> &nums, int sign) {
        int sum = 0, cur = 0;
        for (auto &e : nums) {
            cur = max(0, cur + e * sign);
            sum = max(sum, cur);
        }
        return sum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        return max(kadane(nums, 1), kadane(nums, -1));
    }
};g