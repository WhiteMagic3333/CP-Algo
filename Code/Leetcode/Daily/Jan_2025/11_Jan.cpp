class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a']++;
        }
        int ans = 0;
        for (int f : freq) {
            if (f % 2) {
                ans++;
            }
        }
        return ans <= k && k <= n;
    }
};