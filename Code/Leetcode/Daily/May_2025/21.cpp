class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        bool first_row = false, first_col = false;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            first_row |= grid[i][0] == 0;
        }
        for (int i = 0; i < m; i++) {
            first_col |= grid[0][i] == 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 0) {
                    grid[i][0] = 0;
                    grid[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][0] == 0 || grid[0][j] == 0) {
                    grid[i][j] = 0;
                }
            }
        }
        if (first_row) {
            for (int i = 0; i < n; i++) {
                grid[i][0] = 0;
            }
        }
        if (first_col) {
            for (int i = 0; i < m; i++) {
                grid[0][i] = 0;
            }
        }
    }
};

/*
class Solution {
    const int mx = 4e4;
public:
    void calc(vector<vector<int>>& grid, int &less, int &more, int &equal, int &val) {
        for (auto &row : grid) {
            for (auto &element : row) {
                if (element == val) {
                    equal++;
                } else if (element > val) {
                    more++;
                } else {
                    less++;
                }
            }
        }
    }

    void setZeroes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //using bs find the                                                               
        // using binary search find in low to high, calc how many are small and how many are big
        int low = 0, high = mx, not_present = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int less = 0, more = 0, equal = 0;
            calc(grid, less, more, equal, mid);
            if (equal == 0) {
                not_present = mid;
                break;
            } else if ((mx - mid) > more) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        if (grid[k][j] != 0) {
                            grid[k][j] = not_present;
                        }
                    }
                    for (int k = 0; k < m; k++) {
                        if (grid[i][k] != 0) {
                            grid[i][k] = not_present;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == not_present) {
                    grid[i][j] = 0;
                }
            }
        }
    }
};
*/