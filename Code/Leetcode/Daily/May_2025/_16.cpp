class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for (int i = 0; i < groups.size(); i++) {
            if (i == 0 || groups[i - 1] != groups[i]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};