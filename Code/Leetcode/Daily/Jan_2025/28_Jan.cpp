class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<array<int, 2>> dxy = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    vis[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int sum = 0;
                    while(q.size()) {
                        auto [x, y] = q.front();
                        q.pop();
                        sum += grid[x][y];
                        for (auto d : dxy) {
                            int dx = x + d[0], dy = y + d[1];
                            if (dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy] && !vis[dx][dy]) {
                                q.push({dx, dy});
                                vis[dx][dy] = true;
                            }
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};