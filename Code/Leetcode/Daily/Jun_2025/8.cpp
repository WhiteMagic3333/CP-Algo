class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;
        while (ans.size() != n) {
            ans.push_back(cur);
            if (cur * 10 <= n) {
                cur *= 10;
            } else if (cur % 10 != 9 && cur + 1 <= n) {
                cur += 1;
            } else {
                while ((cur / 10) % 10 == 9) {
                    cur /= 10;
                }
                cur = cur / 10 + 1;
            }
        }
        return ans;
    }
};