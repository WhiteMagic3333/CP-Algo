class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt++;
            } else if (cnt) {
                s[i] = '0';
                cnt--;
            }
        }
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                ans += ch;
            }
        }
        return ans;
    }
};