class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            cnt += nums[i] < nums[i - 1];
        }
        cnt += nums[0] < nums.back();
        return cnt <= 1;
    }
};