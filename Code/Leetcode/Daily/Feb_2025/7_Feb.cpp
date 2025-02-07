class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int dis = 0;
        unordered_map<int, int> color;
        unordered_map<int, int> ball_color;
        for (auto &q : queries) {
            int ball = q[0], col = q[1];
            if (ball_color[ball]) {
                color[ball_color[ball]]--;
                dis -= color[ball_color[ball]] == 0;
            }
            ball_color[ball] = col;
            dis += color[col] == 0;
            color[col]++;
            ans.push_back(dis);
        }
        return ans;
    }
};