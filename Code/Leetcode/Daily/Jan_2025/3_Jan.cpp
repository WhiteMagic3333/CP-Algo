class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long r_sum = accumulate(nums.begin(), nums.end(), 0LL), l_sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            l_sum += nums[i];
            r_sum -= nums[i];
            ans += l_sum >= r_sum;
        }
        return ans;
    }
};