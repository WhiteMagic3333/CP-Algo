class Solution {
public:
    void make_adj_list(vector<vector<int>> &adj, vector<vector<int>> &edges) {
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }

    void dfs(int i, vector<vector<int>> &adj, int &cnt, int k, int p) {
        if (k < 1) {
            return;
        }
        cnt++;
        for (auto u : adj[i]) {
            if (u != p) {
                dfs(u, adj, cnt, k - 1, i);
            }
        }
    }

    int calc(vector<vector<int>>& edges, int k) {
        if (k == 0) {
            return 0;
        }
        int m = edges.size() + 1;
        vector<vector<int>> adj(m);
        make_adj_list(adj, edges);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            dfs(i, adj, cnt, k, -1);
            ans = max(ans, cnt);
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        vector<vector<int>> adj(n);
        make_adj_list(adj, edges1);
        int max_connection_increment = calc(edges2, k);
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            int cnt = max_connection_increment;
            dfs(i, adj, cnt, k + 1, -1);
            answer.push_back(cnt);
        }
        return answer;
    }
};