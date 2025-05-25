class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //palindrome words
        unordered_map<string, int> m;
        for (auto &word : words) {
            m[word]++;
        }
        int extra = 0, ans = 0;
        for (auto &[word, freq] : m) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word == rev) {
                ans += (freq / 2) * 4;
                if (freq % 2) {
                    extra = 1;
                }
            } else if (word < rev && m.count(rev)) {
                ans += min(freq, m[rev]) * 4;
            }
        }
        return ans + extra * 2;
    }
};