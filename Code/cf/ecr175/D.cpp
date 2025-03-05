#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
using namespace std;
typedef long long ll;
ll mod = 998244353;
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

void add(ll &a, ll &b) {
    a += b;
    a %= mod;
}

void sub(ll &a, ll &b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> parent(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }
    vector<vector<ll>> kids(n + 1);
    for (int i = 2; i <= n; i++) {
        kids[parent[i]].push_back(i);
    }
    vector<ll> dp(n + 1, 0);
    vector<ll> level(n + 1, 0);
    dp[1] = level[1] = 1;
    ll ans = 0, cur_level_kids = kids[1].size();
    queue<ll> q;
    for (auto k : kids[1]) {
        q.push(k);
        parent[k] = 0;
    }
    int lvl = 2;
    while (q.size()) {
        ll next_level_kids = 0;
        while (cur_level_kids--) {
            ll cur = q.front();
            q.pop();
            add(dp[cur], level[lvl - 1]);
            sub(dp[cur], dp[parent[cur]]);
            add(level[lvl], dp[cur]);
            for (auto k : kids[cur]) {
                q.push(k);
                next_level_kids++;
            }
        }
        cur_level_kids = next_level_kids;
        lvl++;
    }
    for (int i = 1; i <= n; i++) {
        add(ans, dp[i]);
    }
    cout << ans;
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