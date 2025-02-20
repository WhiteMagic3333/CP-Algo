class Solution {
public:

    bool rec(string &cur, vector<string> &nums, int n) {
        if (n == 0) {
            for (auto &str : nums) {
                if (str == cur) {
                    return false;
                }
            }
            return true;
        }
        for (char ch = '0'; ch <= '1'; ch++) {
            cur.push_back(ch);
            if (rec(cur, nums, n - 1)) {
                return true;
            }
            cur.pop_back();
        }
        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string cur = "";
        rec(cur, nums, nums.size());
        return cur;
    }
};