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

int n, m;

ll mn = 2e18;


void rec(vector<vector<array<ll, 2>>> &adj, vector<bool> &vis, ll i, ll x) {
    if (i == n) {
        mn = min(mn, x);
        return;
    }
    vis[i] = true;
    for (auto cur : adj[i]) {
        ll u = cur[0];
        ll w = cur[1];
        if (!vis[u]) {
            rec(adj, vis, u, (x ^ w));
        }
    }
    vis[i] = false;
}

 
void solve()
{
    cin >> n >> m;
    vector<vector<array<ll, 2>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<bool> vis(n + 1, false);
    rec(adj, vis, 1LL, 0LL);
    cout << mn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}