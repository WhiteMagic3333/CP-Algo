class Solution {
private:
    int r, c;
public:
    pair<int, int> num_to_coordinate(int num) {
        num--;
        int row = num / r;
        int col = num % c;
        if (row % 2) {
            col = c - 1 - col;
        }
        row = r - 1 - row;
        return {row, col};
    }

    void add(int &i, int &j) {
        int sign = (r - 1 - i) % 2 ? -1 : 1;
        if ((j + sign) < 0 || (j + sign) >= c) {
            i = max(0, i - 1);
            sign *= -1;
        } else {
            j += sign;
        }
    }    

    int snakesAndLadders(vector<vector<int>>& grid) {
        int n;
        r = c = n = grid.size();
        vector<vector<int>> moves(n, vector<int> (n, -1));
        queue<array<int, 2>> q;
        moves[n - 1][0] = 0;
        q.push({n - 1, 0});
        while (q.size()) {
            int i = q.front()[0], j = q.front()[1];
            int old_moves = moves[i][j];
            q.pop();
            for (int k = 1; k <= 6; k++) {
                add(i, j);
                // cout << i << " " <<j << " " << moves[i][j] << " " << "\n";
                if (grid[i][j] == -1) {
                    if (moves[i][j] == -1) {
                        moves[i][j] = old_moves + 1;
                        q.push({i, j});
                    }
                } else {
                    auto [x, y] = num_to_coordinate(grid[i][j]);
                    if (moves[x][y] == -1) {
                        q.push({x, y});
                        moves[x][y] = old_moves + 1;
                    } 
                }
            }
        }
        int i = 0, j = n % 2 ? n - 1 : 0;
        return moves[i][j];
    }
};