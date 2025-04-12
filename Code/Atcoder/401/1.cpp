#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 2e5 + 1;
vector<int> g[N];
int bit[2 * N], in[N], out[N], a[N], n, q, tmr;
 
void dfs(int u, int p = 0) {
    in[u] = ++tmr;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = ++tmr;
}
 
void upd(int pos, int x) {
    for (int i = pos; i <= tmr; i += i & -i) {
        bit[i] += x;
    }
}
 
int ask(int pos) {
    int sum = 0;
    for (int i = pos; i; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        upd(out[i], a[i]);
    }
    while (q--) {
        int tp, u;
        cin >> tp >> u;
        if (tp == 1) {
            int x;
            cin >> x;
            upd(out[u], x - a[u]);
            a[u] = x;
        } else {
            cout << ask(out[u]) - ask(in[u]) << '\n';
        }
    }
}