class Solution {
public:
    void dfs(vector<int> &fav, vector<bool> &vis, vector<int> &idx, int &ans, int i, int level) {
        if (vis[i]) {
            if (idx[i] != 0) {
                ans = max(ans, level - idx[i]);
            }
            return;
        }
        vis[i] = true;
        idx[i] = level;
        dfs(fav, vis, idx, ans, fav[i], level + 1);
        idx[i] = 0;
    }

    int maximumInvitations(vector<int>& fav) {
        //get the max cycle size
        //guarenteed to have a cycle
        //for cycles of size 2, get the max path it can make
        int n = fav.size();
        vector<int> idx(n, 0);
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(fav, vis, idx, ans, i, 1);
            }
        }
        fill(vis.begin(), vis.end(), false);
        return ans;
    }
};