class Solution {
public:
    vector<vector<int>> dxy = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    int trapRainWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
        for (int i = 0; i < n; i++) {
            vis[i][0] = vis[i][m - 1] = true;
            q.push({grid[i][0], i, 0});
            q.push({grid[i][m - 1], i, m - 1});
        }
        for (int j = 1; j < m - 1; j++) {
            vis[0][j] = vis[n - 1][j] = true;
            q.push({grid[0][j], 0, j});
            q.push({grid[n - 1][j], n - 1, j});
        }
        long long ans = 0;
        while(q.size()) {
            int i = q.top()[1], j = q.top()[2], mx_h = q.top()[0];
            q.pop();
            for (auto d : dxy) {
                int di = i + d[0];
                int dj = j + d[1];
                if (min(di, dj) >= 0 && di < n && dj < m && !vis[di][dj]) {
                    vis[di][dj] = true;
                    if (grid[di][dj] < mx_h) {
                        ans += mx_h - grid[di][dj];
                        q.push({mx_h, di, dj});
                    } else {
                        q.push({grid[di][dj], di, dj});
                    }
                }
            }
        }
        return ans;
    }
};