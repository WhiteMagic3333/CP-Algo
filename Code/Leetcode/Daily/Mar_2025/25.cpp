class Solution {
public:
    bool check(vector<pair<int, int>> &cur) {
        sort(cur.begin(), cur.end());
        int cnt = 0, sum = 0;
        for (auto &r : cur) {
            sum += r.second;
            cnt += (sum == 0);
        }
        return cnt > 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> _x, _y; // diff array for both _x and _y, kal bhi kar skta tha
        for (auto &rec : rectangles) {
            _x.emplace_back(rec[0], 1);
            _y.emplace_back(rec[1], 1);
            _x.emplace_back(rec[2], -1);
            _y.emplace_back(rec[3], -1);
        }
        return check(_y) || check(_x);
    }
};