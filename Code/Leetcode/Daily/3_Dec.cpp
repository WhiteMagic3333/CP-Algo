class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int count_spaces = spaces.size();
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (j < count_spaces && i == spaces[j]) {
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};