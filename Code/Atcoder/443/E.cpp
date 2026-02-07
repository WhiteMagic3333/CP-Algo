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
        std::cout << x;
    std::cout << '\n';
    return out;
}
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }
    vector<ll> row_sum(n, 0);
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});
    string dir = "LRUD";
    vector<array<int, 2>> dxy = {{-1, -1}, {-1, 0}, {-1, 1}};
    vector<vector<bool>> vis(n, vector<bool> (n, false));
    vis[n - 1][m - 1] = true;
    q.push({n - 1, m - 1});
    int prev = n;
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        if (i != prev) {
            for (int _j = 0; _j < n; _j++) {
                row_sum[_j] += (grid[i][_j] == '#');
            }
            prev = i;
        }
        for (auto d : dxy) {
            int dx = d[0] + i, dy = d[1] + j;
            if (dx >= 0 && dy >= 0 && dx < n && dy < n && !vis[dx][dy] && (grid[dx][dy] == '.' || row_sum[dy] == 0)) {
                grid[dx][dy] = '.';
                q.push({dx, dy});
                vis[dx][dy] = true;
            }
        }
    }
    cout << vis[0];
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
    }
    return 0;
}