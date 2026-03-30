#include <numeric>
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

vector<int> comp;

int n, m;

vector<array<int, 2>> dxy = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};

void dfs(vector<string> &grid, vector<vector<bool>> &vis, int i, int j) {
    vis[i][j] = true;
    for (auto d : dxy) {
        int dx = i + d[0], dy = j + d[1];
        if (dx < 0 || dy < 0 || dx >= n || dy >= m) {
            comp.back() = 0;
            continue;
        }
        if (grid[dx][dy] == '#' || vis[dx][dy]) {
            continue;
        }
        dfs(grid, vis, dx, dy);
    }
}

void solve()
{
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                comp.push_back(1);
                dfs(grid, vis, i, j);
            }
        }
    }
    cout << accumulate(comp.begin(), comp.end(), 0);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}