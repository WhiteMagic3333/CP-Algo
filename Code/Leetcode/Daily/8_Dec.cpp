// https://leetcode.com/problems/two-best-non-overlapping-events/?envType=daily-question&envId=2024-12-08

class Solution {
public:
    static bool custom_sort(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    int maxTwoEvents(vector<vector<int>>& cur) {
        // Sort events by start time
        int n = cur.size();
        vector<vector<int>> events = cur;
        sort(events.begin(), events.end(), custom_sort);
        int max_value = 0;
        for (int i = n - 1; i >= 0; i--) {
            max_value = max(max_value, events[i][2]);
            events[i].push_back(max_value);
        }
        long long ans = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < events[i].size(); j++) {
        //         cout << events[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        for (int i = 0; i < n; i++) {
            long long cur_value = events[i][2];
            long long other_value = 0;
            vector<int> cur = events[i];
            cur[0] = events[i][1] + 1;
            cur[1] = cur[2] = cur[3] = 0;
            auto oth = lower_bound(events.begin(), events.end(), cur);
            int index = oth - events.begin();
            if (oth != events.end()) {
                if (i == index) {
                    oth++;
                    if (oth != events.end()) {
                        other_value = (*oth)[3];
                    }
                } else {
                    other_value = (*oth)[3];
                }
            }
            ans = max(ans, cur_value + other_value);
            // cout << ans << " ";
        }
        return ans;
    }
};