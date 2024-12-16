class Solution {
public:
    char next_char(char ch) {
        if (ch == 'z') {
            return 'a';
        }
        return ch + 1;
    }

    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int count = 0, i = 0;
        while(i < n) {
            if (str1[i] == str2[count] || next_char(str1[i]) == str2[count]) {
                count++;
                if (count == m) {
                    return true;
                }
            }
            i++;
        }
        return false;
    }
};