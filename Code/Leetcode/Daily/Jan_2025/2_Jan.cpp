class Solution {
public:
    int calc(vector<int> &pre, int l, int r) {
        int low = l == 0 ? 0 : pre[l - 1];
        return pre[r] - low;
    }

    bool is_vowel(char ch) {
        vector<char> cur = {'a', 'e', 'i', 'o', 'u'};
        for (char c : cur){
            if (ch == c) {
                return true;
            }
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (is_vowel(words[i][0]) && is_vowel(words[i].back())) {
                pre[i]++;
            }
            pre[i] += (i == 0 ? 0 : pre[i - 1]);
        }
        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(calc(pre, q[0], q[1]));
        }
        return ans;
    }
};