class Solution {
public:
    void get_permutation(vector<int> &nums, set<vector<int>> &s, vector<int> &cur, int &bit, int rem) {
        if (rem == 0) {
            s.insert(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            //00
            int pow2 = (nums.size() - 1 - i);
            bool used = (1 << pow2) & bit;
            if (!used) {
                bit = bit | (1 << pow2);//dd
                cur.push_back(nums[i]);
                get_permutation(nums, s, cur, bit, rem);
                bit = bit ^ (1 << pow2);//remove
                cur.pop_back();
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
    set<vector<int>> s;
    vector<vector<int>> ans;
    vector<int> cur;
    int bit = 0;// 00000 no selected
    int n = nums.size();
    get_permutation(nums, s, cur, bit, n);
}