class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> pre_req(n, vector<bool> (n, false));
        vector<vector<int>> adj(n);
        for (vector<int> &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            q.push(i);
            while(q.size()) {
                int cur = q.front();
                q.pop();
                pre_req[cur][i] = true;
                for (auto &v : adj[cur]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            fill(vis.begin(), vis.end(), false);
        }
        vector<bool> ans;
        for (vector<int> &cur : queries) {
            if (pre_req[cur[1]][cur[0]]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};