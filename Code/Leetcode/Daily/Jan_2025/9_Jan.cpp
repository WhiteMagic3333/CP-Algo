class Solution {
public:

    bool prefix(string &a, string &b) {
        if (a.length() < b.length()) {
            return false;
        }
        for (int i = 0; i < b.length(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto word : words) {
            if (prefix(word, pref)) {
                ans++;
            }
        }
        return ans;
    }
};