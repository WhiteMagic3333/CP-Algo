#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct node {
    char let;  // Character at the position
    int place; // Some metric (distance or step count)
    int i, j;  // Position in the grid
    
    // Custom comparison operator to use with the priority queue
    bool operator>(const node& other) const {
    // First compare by place (smaller comes first)
        if (place == other.place) {
            return let > other.let;  // If places are the same, compare by lexicographically smaller letter
        }
        return place > other.place;  // Otherwise, compare by place
    }
};

vector<char> dp;

node create_node(char let, int place, int i, int j) {
    node n;
    n.let = let;
    n.place = place; //is it the 0th, 1st place ... 
    n.i = i;
    n.j = j;
    dp[place] = min(dp[place], let);
    return n;
}

void print(node n) {
    cout << n.let << " " << n.place << " " << n.i << " " << n.j << "\n";
}

void solve() {
    int n;
    cin >> n;

    dp = vector<char> (2 * n, 'Z');
    
    vector<string> grid(n);
    for (auto &s : grid) {
        cin >> s;
    }
    
    // To track visited positions
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string ans = "";
    
    // Min-heap priority queue (default comparison is now by place, then by let)
    queue<node> q;
    
    // Starting point at (0, 0)
    q.push(create_node(grid[0][0], 0, 0, 0));
    vis[0][0] = true;
    
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        if (dp[cur.place] < cur.let) {
            continue;
        }
        
        // Collect characters based on place
        if (cur.place == ans.length()) {
            ans.push_back(cur.let);
        }
        
        if (cur.j + 1 >= n || cur.i + 1 >= n || grid[cur.i][cur.j + 1] == grid[cur.i + 1][cur.j]) {
            // Move right (cur.j + 1)
            if (cur.j + 1 < n && !vis[cur.i][cur.j + 1]) {
                vis[cur.i][cur.j + 1] = true;
                q.push(create_node(grid[cur.i][cur.j + 1], cur.place + 1, cur.i, cur.j + 1));
            }
            
            // Move down (cur.i + 1)
            if (cur.i + 1 < n && !vis[cur.i + 1][cur.j]) {
                vis[cur.i + 1][cur.j] = true;
                q.push(create_node(grid[cur.i + 1][cur.j], cur.place + 1, cur.i + 1, cur.j));
            }
        } else {
            if (grid[cur.i][cur.j + 1] < grid[cur.i + 1][cur.j]) {
                if (!vis[cur.i][cur.j + 1]) {
                    vis[cur.i][cur.j + 1] = true;
                    q.push(create_node(grid[cur.i][cur.j + 1], cur.place + 1, cur.i, cur.j + 1));
                }
            } else {
                if (!vis[cur.i + 1][cur.j]) {
                    vis[cur.i + 1][cur.j] = true;
                    q.push(create_node(grid[cur.i + 1][cur.j], cur.place + 1, cur.i + 1, cur.j));
                }
            }
        }
    }
    
    cout << ans;
}

int main() {
    solve();
    return 0;
}
