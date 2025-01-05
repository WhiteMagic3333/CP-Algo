class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        for (auto &shift : shifts) {
            if (shift[2] == 1) {
                diff[shift[0]]++;
                diff[shift[1] + 1]--;
            } else {
                diff[shift[0]]--;
                diff[shift[1] + 1]++;
            }
        }
        int d = 0;
        for (int i = 0; i < n; i++) {
            d += diff[i];
            if (d < 0) {
                d = (d % 26) + 26;
            } else {
                d = d % 26;
            }
            char ch = s[i] - 26;
            ch += d;
            if (ch < 'a') {
                ch = ch + 26;
            }
            s[i] = ch;
        }
        return s;
    }
};