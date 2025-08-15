#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> color(n + 1);
        for (int i = 1; i <= n; i++) cin >> color[i];

        vector<vector<Edge>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            long long c;
            cin >> u >> v >> c;
            g[u].push_back({v, c});
            g[v].push_back({u, c});
        }

        vector<int> parent(n + 1, -1);
        vector<long long> edgeCost(n + 1, 0);
        vector<map<int, long long>> mem(n + 1);

        // DFS to set parent, edge cost and fill mem
        function<void(int,int)> dfs = [&](int v, int p) {
            for (auto &e : g[v]) {
                int u = e.to;
                if (u == p) continue;
                parent[u] = v;
                edgeCost[u] = e.w;
                dfs(u, v);
                mem[v][color[u]] += e.w;
            }
        };
        dfs(1, -1);

        // initial answer
        long long ans = 0;
        for (int v = 2; v <= n; v++) {
            if (color[v] != color[parent[v]]) ans += edgeCost[v];
        }

        while (q--) {
            int v, x;
            cin >> v >> x;
            int old = color[v];
            if (old == x) {
                cout << ans << "\n";
                continue;
            }

            // handle edges to children
            ans += mem[v][old]; // previously free, now paid
            ans -= mem[v][x];   // previously paid, now free

            // handle edge to parent
            if (parent[v] != -1) {
                long long w = edgeCost[v];
                if (old != color[parent[v]]) ans -= w;
                if (x != color[parent[v]]) ans += w;

                // update parent's mem
                mem[parent[v]][old] -= w;
                if (mem[parent[v]][old] == 0) mem[parent[v]].erase(old);
                mem[parent[v]][x] += w;
            }

            color[v] = x;
            cout << ans << "\n";
        }
    }
    return 0;
}
