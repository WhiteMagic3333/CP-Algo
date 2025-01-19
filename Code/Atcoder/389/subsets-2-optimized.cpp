void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> &cur, int i) {
        ans.push_back(cur); //empty
        for (int idx = i; idx < nums.size(); idx++) {

            cur.push_back(nums[idx]);

            subset(nums, ans, cur, idx + 1); //somehow

            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        subset(nums, ans, cur, 0);
        return ans;
    }