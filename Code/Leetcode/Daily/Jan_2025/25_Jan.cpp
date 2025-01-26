class Solution {
public:
    void get_permutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &cur, unordered_map<int, bool> used, int rem) {
        if (rem == 0) {
            ans.emplace_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                cur.push_back(nums[i]);
                get_permutation(nums, ans, cur, used, rem - 1);
                cur.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_map<int, bool> used;
        int n = nums.size();
        get_permutation(nums, ans, cur, used, n);
        return ans;
    }
};