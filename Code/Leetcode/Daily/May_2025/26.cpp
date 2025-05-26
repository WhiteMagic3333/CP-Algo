class Solution { //
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<array<int,26>> dp(n);
        int seen = 0, ans = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            seen++;
            int c = colors[u] - 'a';
            dp[u][c]++;
            ans = max(ans, dp[u][c]);
            for (int v : adj[u]) {
                for (int k = 0; k < 26; k++){
                    dp[v][k] = max(dp[v][k], dp[u][k]);
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return seen == n ? ans : -1;
    }
};