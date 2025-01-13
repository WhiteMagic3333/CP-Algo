class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int ans = 0;
        for (int fr : freq) {
            ans += min(fr, fr % 2 ? 1 : 2);
        }
        return ans;
    }
};