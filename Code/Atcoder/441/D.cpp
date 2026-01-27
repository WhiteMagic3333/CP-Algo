#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
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
 
void solve()
{
    ll n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<vector<ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    queue<array<ll, 3>> q; //node, rem L, cum-cost
    vector<bool> valid(n + 1, false);
    q.push({1, l, 0});
    while (q.size()) {
        array<ll, 3> cur = q.front();
        q.pop();
        if (cur[1] == 0) {
            if (cur[2] >= s && cur[2] <= t) {
                valid[cur[0]] = true;
            }
        } else {
            for (auto u : adj[cur[0]]) {
                if (cur[2] + u[1] <= t) {
                    q.push({u[0], cur[1] - 1, cur[2] + u[1]});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (valid[i]) {
            cout << i << " ";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}