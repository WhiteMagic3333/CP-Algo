#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int H, W;
vector<string> grid;

// DP table to store the minimum repaints required for each configuration of rows
vector<vector<int>> dp;

// Function to check if any 2x2 subgrid is fully black given the current state
bool isValid(int row1, int row2) {
    for (int j = 0; j < W - 1; ++j) {
        if ((row1 & (1 << j)) && (row1 & (1 << (j + 1))) && 
            (row2 & (1 << j)) && (row2 & (1 << (j + 1)))) {
            return false; // 2x2 block is fully black
        }
    }
    return true;
}

// Function to convert the grid row to a bitmask representation
int rowToMask(const string& row) {
    int mask = 0;
    for (int i = 0; i < W; ++i) {
        if (row[i] == '#') {
            mask |= (1 << i); // Set bit for black cell
        }
    }
    return mask;
}

void solve() {
    cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    // Initialize DP table with a large value
    dp.assign(H + 1, vector<int>(1 << W, INF)); // dp[row][mask]
    dp[0][0] = 0;  // 0th row, no cells changed, 0 cost

    // Process each row
    for (int row = 1; row <= H; ++row) {
        int currentRowMask = rowToMask(grid[row - 1]);  // Mask for current row
        for (int prevMask = 0; prevMask < (1 << W); ++prevMask) {  // Iterate over previous row configurations
            for (int mask = 0; mask < (1 << W); ++mask) {  // Try every configuration for the current row
                int cost = __builtin_popcount(mask); // Cost is the number of 1s (repaints)
                if (dp[row - 1][prevMask] != INF && isValid(prevMask, mask)) {
                    dp[row][mask] = min(dp[row][mask], dp[row - 1][prevMask] + cost);
                }
            }
        }
    }

    // Find the minimum value in the last row of DP table
    int result = INF;
    for (int mask = 0; mask < (1 << W); ++mask) {
        result = min(result, dp[H][mask]);
    }

    cout << result << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
