class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        //multisource bfs :P
        //kab se wait kar raha tha iska
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<array<int, 2>> dxy = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        int dis = 0;
        while(q.size()) {
            auto [i, j] = q.front();
            q.pop();
            dis = max(dis, ans[i][j]);
            for (auto d : dxy) {
                int di = i + d[0];
                int dj = j + d[1];
                if (di >= 0 && dj >= 0 && di < n && dj < m && ans[di][dj] == -1) {
                    q.push({di, dj});
                    ans[di][dj] = dis + 1;
                }
            }
        }
        return ans;
    }
};

