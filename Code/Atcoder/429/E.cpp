#include <array>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string str;
    cin >> str;
    vector<vector<array<int, 2>>> closest(n + 1);
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'S') {
            q.push({i + 1, i + 1, 0});
            closest[i + 1].push_back({i + 1, 0});
        }
    }
    while (q.size()) {
        auto [i, st, dis] = q.front();
        q.pop();
        for (auto u : adj[i]) {
            if (closest[u].size() == 0 || (closest[u].size() == 1 && closest[u][0][0] != st)) {
                closest[u].push_back({st, dis + 1});
                q.push({u, st, dis + 1});
            }
        }
    }gmaighttps://hentaihaven.video/browse?sort=viewhttps://hentaihaven.video/browse?sort=viewsssfgasdf
    for (int i = 1; i <= n; i++) {
        if (str[i - 1] == 'D') {
            cout << closest[i][0][1] + closest[i][1][1] << "\n";
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