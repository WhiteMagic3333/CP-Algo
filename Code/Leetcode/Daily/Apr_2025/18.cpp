class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            string rle = "";
            int i = 0, j;
            while (i < ans.size()) {
                j = i;
                while (j < ans.size() && ans[i] == ans[j]) {
                    j++;
                }
                rle += to_string(j - i) + ans[i];
                i = j;
            }
            ans = rle;
        }
        return ans;
    }
};