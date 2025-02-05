class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool is_same = true;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                is_same = false;
                break;
            }
        }
        return is_same && diff < 3;
    }
};