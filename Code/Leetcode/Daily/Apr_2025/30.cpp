class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) {
            string str = to_string(i);
            ans += str.length() % 2 == 0;
        }
        return ans;
    }
};