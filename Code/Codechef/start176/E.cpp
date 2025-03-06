#include <array>
#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_map>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
vector<int> primes;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
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

void rec(vector<vector<ll>> &adj, vector<ll> &val, int idx, int par, ll &ans, ll mn) {
    mn = min(mn, val[idx]);
    ans += mn;
    for (auto u : adj[idx]) {
        if (u != par) {
            rec(adj, val, u, idx, ans, mn);
        }
    }
}
 
void solve()
{
    int n;
    cin >> n;
    vector<ll> val(n);
    cin >> val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < primes.size(); j++) {
            if (val[i] % primes[j] != 0) {
                val[i] = primes[j];
                break;
            }
        }
    }
    vector<vector<ll>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 1e9;
    vector<vector<ll>> f(n + 1, vector<ll> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        ll ans = 0;
        rec(adj, val, i, -1, ans, val[i]);
        cout << ans << " ";
    }

}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    sieve(1000);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}