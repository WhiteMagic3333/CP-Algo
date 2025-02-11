class Solution {
public:
    bool check(string &s, int i, string &part) {
        for (int j = 0; j < part.length(); j++, i++) {
            if (i >= s.length() || s[i] != part[j]) {
                return false;
            }
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        while(1) {
            string cpy = "";
            bool found = false;
            for (int i = 0; i < s.length(); i++) {
                if (check(s, i, part) && !found) {
                    found = true;
                    i += part.length() - 1;
                } else {
                    cpy += s[i];
                }
            }
            s = cpy;
            if (!found) {
                break;
            }
        }
        return s;
    }
};g