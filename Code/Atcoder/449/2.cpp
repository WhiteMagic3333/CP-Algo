void dfs1(int u, int p, const vector<vector<pair<int, int>>>& adj, int& initial_reversals) {
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        int cost = edge.second;
        if (v != p) {
            initial_reversals += cost;
            dfs1(v, u, adj, initial_reversals);
        }
    }
}

// Step 3: Second DFS for Re-rooting
// Passed by reference: adj, ans, and min_reversals
void dfs2(int u, int p, const vector<vector<pair<int, int>>>& adj, vector<int>& ans, int& min_reversals) {
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        int cost = edge.second;
        if (v != p) {
            // If original edge was u->v (cost 0), moving root to v adds 1 reversal
            // If original edge was v->u (cost 1), moving root to v subtracts 1 reversal
            ans[v] = ans[u] + (cost == 0 ? 1 : -1);
            
            // Track the minimum as we go
            min_reversals = min(min_reversals, ans[v]);
            
            dfs2(v, u, adj, ans, min_reversals);
        }
    }
}

int getMinInversions(int g_nodes, vector<int> from, vector<int> to) {
    // Step 1: Build the graph
    // adj[u] will store pairs of {neighbor, cost}
    // cost is 0 if edge is u -> v (correct direction)
    // cost is 1 if edge is v -> u (needs reversal)
    vector<vector<pair<int, int>>> adj(g_nodes + 1);
    for (int i = 0; i < from.size(); ++i) {
        adj[from[i]].push_back({to[i], 0});
        adj[to[i]].push_back({from[i], 1});
    }

    int initial_reversals = 0;

    // Run first pass from arbitrary root (Node 1), parent is 0
    dfs1(1, 0, adj, initial_reversals);

    vector<int> ans(g_nodes + 1, 0);
    ans[1] = initial_reversals;
    int min_reversals = ans[1];

    // Run second pass to calculate for all other nodes
    dfs2(1, 0, adj, ans, min_reversals);

    return min_reversals;
}