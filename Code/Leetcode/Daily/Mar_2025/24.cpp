class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int st = 1e9, ed = meetings[0][1], ans = 0;
        for (auto m : meetings) {
            if (m[0] > ed) {
                ans += (m[0] - ed - 1);
            }
            ed = max(ed, m[1]);
        }
        ans += days - ed + (meetings[0][0] - 1);
        return ans;
    }
};