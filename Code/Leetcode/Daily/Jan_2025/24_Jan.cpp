class Solution {
public:
    bool is_safe(vector<vector<int>> &graph, vector<bool> &safe, vector<bool> &vis, int i) {
        if (vis[i]) {
            return safe[i];
        }
        vis[i] = true;
        safe[i] = false;
        bool safe_neighbours = true;
        for (auto u : graph[i]) {
            safe_neighbours = safe_neighbours && is_safe(graph, safe, vis, u);
        }
        safe[i] = safe_neighbours;
        return safe[i];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safe(n, true);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                is_safe(graph, safe, vis, i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};