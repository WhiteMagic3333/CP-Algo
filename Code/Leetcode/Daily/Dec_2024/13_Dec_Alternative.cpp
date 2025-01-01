class Solution {
public:

    long long findScore(vector<int>& nums) {
        set<array<int, 2>> s;
        vector<bool> marked(n + 1, false);
        int index = 0;
        for (auto cur : nums) {
            s.insert({cur, index + 1});
            index++;
        }
        long long ans = 0;
        while(s.size()) {
            auto smallest = s.begin();
            int index = (*smallest)[1];
            s.erase(smallest);
            if (marked[index]) {
                continue;
            }
            ans += nums[index - 1];
            marked[i - 1] = marked[i + 1] = marked[i] = true;
        }
        return ans;
    }
};