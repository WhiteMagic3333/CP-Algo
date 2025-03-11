class Solution {
public:
    int numberOfSubstrings(string &s) {
        array<int, 3> freq;
        int n = s.length(), i = 0, j = 0, u = 0;
        long long ans = 0;
        while (j < n) {
            while (j < n && u < 3) {
                if (freq[s[j] - 'a'] == 0) {
                    u++;
                }
                freq[s[j] - 'a']++;
                j++;
            }
            while (u == 3) {
                ans += 1 + (n - j);
                if (freq[s[i] - 'a'] == 1) {
                    u--;
                }
                freq[s[i] - 'a']--;
                i++;
            }
        }
        return ans;
    }
};