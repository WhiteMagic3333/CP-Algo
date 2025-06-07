class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> alpha_idx(26);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (alpha_idx[j].size()) {
                        int k = alpha_idx[j].top();
                        alpha_idx[j].pop();
                        s[k] = '*';
                        break;
                    }
                }
            } else {
                int ch = s[i] - 'a';
                alpha_idx[ch].push(i);
            }
        }
        string ans = "";
        for (char ch : s) {
            if (ch != '*') {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};