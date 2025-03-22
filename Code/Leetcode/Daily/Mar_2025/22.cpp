class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int i, vector<int> &cur) {
        cur.push_back(i);
        vis[i] = true;
        for (auto &u : adj[i]) {
            if (!vis[u]) {
                dfs(adj, vis, u, cur);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //degree of each node should be no_of_nodes in the component - 1
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<int> cur;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, vis, i, cur);
                bool valid = true;
                for (auto &node : cur) {
                    valid &= adj[node].size() == (cur.size() - 1);
                }
                ans += valid;
                cur.clear();
            }
        }
        return ans;
    }
};