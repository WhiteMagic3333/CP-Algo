class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool valid = true;
        for (int i = 1; i < nums.size(); i++) {
            valid = valid & ((nums[i - 1] % 2) != (nums[i] % 2));
        }
        return valid;
    }
};