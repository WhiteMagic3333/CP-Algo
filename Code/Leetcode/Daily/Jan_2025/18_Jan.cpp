class Solution {
public:
    vector<vector<int>> dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    array<int, 2> get(int ch, int i, int j) {
        i += dir[ch - 1][0];
        j += dir[ch - 1][1];
        return {i, j};
    }

    bool valid(int i, int j, int n, int m) {
        if (min(i, j) < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 1e9));
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
        
        q.push({0, 0, 0});
        ans[0][0] = 0;
        while(q.size()) {
            auto [cur, i, j] = q.top();
            q.pop();
            if (!vis[i][j]) {
                vis[i][j] = true;
                auto [i1, j1] = get(grid[i][j], i, j);
                if (valid(i1, j1, n, m) && ans[i1][j1] > cur) {
                    ans[i1][j1] = cur;
                    q.push({cur, i1, j1});
                }
                for (auto d : dir) {
                    int i2 = i + d[0];
                    int j2 = j + d[1];
                    if (valid(i2, j2, n, m) && (ans[i2][j2] > (cur + 1))) {
                        q.push({cur + 1, i2, j2});
                        ans[i2][j2] = cur + 1;
                    }
                }
            }
        }
        return ans[n - 1][m - 1];
    }
};