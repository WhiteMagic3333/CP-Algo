#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}
 
template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}
 
template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}

bool has_cycle(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &vis_no_cycle, int i) {
    vis[i] = true;
    for (auto u : adj[i]) {
        if (vis_no_cycle[u]) {
            continue;
        }
        if (vis[u] || has_cycle(adj, vis, vis_no_cycle, u)) {
            return true;
        }
    }
    vis_no_cycle[i] = true;
    return false;
}
 
void solve()
{
    //city, weekday if visited then dont get into that city
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
        edges.push_back({v, u});
    }
    int w;
    cin >> w;
    vector<string> str(n);
    for (auto &row : str) {
        cin >> row;
    }
    for (int i = 0; i < n; i++) {
        edges.push_back({i, i});
    }
    vector<vector<int>> adj(n * w + 1);
    for (auto &[u, v] : edges) {
        for (int i = 0; i < w; i++) {
            int j = (i + 1) % w;
            if (str[u][i] == 'o' && str[v][j] == 'o') {
                adj[u + n * i].push_back({v + n * j});
            }
        }
    }
    n = adj.size();
    vector<bool> vis(n, false), vis_no_cycle(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (has_cycle(adj, vis, vis_no_cycle, i)) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}