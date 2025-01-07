class Solution {
public:
    bool substr(string &a, string &b) {
        for (int i = 0; i < b.length(); i++) {
            bool found  = true;
            for (int j = 0; j < a.length(); j++) {
                if ((j + i) >= b.length() || b[i + j] != a[j]) {
                    found = false;
                    break;
                }     
            }
            if (found) {
                return true;
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
       int n = words.size();
       vector<string> ans;
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
                if (i != j && substr(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
           }
       }
       return ans;
    }
};