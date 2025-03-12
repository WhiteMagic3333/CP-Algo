class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = n - (int)(lower_bound(nums.begin(), nums.end(), 1) - nums.begin());
        return max(neg, pos);
    }
};