class Solution {
public:
    vector<vector<int>> dxy = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    void w_level(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<int>> &ans, int &mxlevel, int &mnlevel, int i, int j) {
        if (vis[i][j] == 2) {
            mxlevel = min(mxlevel, ans[i][j]);
        } else if (vis[i][j] == 0) {
            vis[i][j] = 1;
            for (auto d : dxy) {
                int di = i + d[0];
                int dj = j + d[1];
                if (mnlevel < grid[di][dj]) {
                    mxlevel = min(mxlevel, grid[di][dj]);
                } else {
                    w_level(grid, vis, ans, mxlevel, mnlevel, di, dj);
                }
            }
        }
    }

    void fill(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<int>> &ans, int &level, int i, int j) {
        ans[i][j] = max(0, level - grid[i][j]);
        for (vector<int> d : dxy) {
            int di = i + d[0];
            int dj = j + d[1];
            if (vis[di][dj] == 1) {
                vis[di][dj] = 2;
                fill(grid, vis, ans, level, di, dj);
            }
        }
    }


    int trapRainWater(vector<vector<int>>& grid) {
        // if neighbour is taller then store the min tallest neigbou
        // if neightbour is smaller then do bfs with neighbour while keeping the least tallest neighbour info
        // if cur is border then all whole grid loses capacity or if
        // capacity for cur is 0 and is found to be a smaller or equal
        // neighbour then capacity for cur-zone is zero
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            vis[i][0] = vis[i][m - 1] = 2;
        }
        for (int j = 1; j < m - 1; j++) {
            vis[0][j] = vis[n - 1][j] = 2;
        }
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                q.push({grid[i][j], i, j});
            }
        }
        while(q.size()) {
            int i = q.top()[1];
            int j = q.top()[2];
            if (!vis[i][j]) {
                int mx_lev = 1e5;
                int mn_lev = q.top()[0];
                w_level(grid, vis, ans, mx_lev, mn_lev, i, j);
                fill(grid, vis, ans, mx_lev, i, j);    
            }
            break;
            q.pop();
        }

        long long units = 0;
        for (vector<int> &row : vis) {
            units += accumulate(row.begin(), row.end(), 0LL);
            for (auto col : row) {
                cout << col << " ";
            }
            cout << "\n";
        }
        for (vector<int> &row : ans) {
            units += accumulate(row.begin(), row.end(), 0LL);
            for (auto col : row) {
                cout << col << " ";
            }
            cout << "\n";
        }
        return units;
    }
};