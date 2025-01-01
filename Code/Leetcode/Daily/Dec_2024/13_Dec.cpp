class Solution {
public:

    long long findScore(vector<int>& nums) {
        set<array<int, 2>> s;
        int index = 0;
        for (auto cur : nums) {
            s.insert({cur, index});
            index++;
        }
        long long ans = 0;
        while(s.size()) {
            auto sm = s.begin();
            long long val = (*sm)[0];
            index = (*sm)[1];
            ans += val;
            if (index != 0) {
                auto left = s.find({nums[index - 1], index - 1});
                if (left != s.end()) {
                    s.erase(left);
                }
            }
            if (index != nums.size() - 1) {
                auto right = s.find({nums[index + 1], index + 1});
                if (right != s.end()) {
                    s.erase(right);
                }
            }
            s.erase(sm);
        }
        return ans;
    }
};