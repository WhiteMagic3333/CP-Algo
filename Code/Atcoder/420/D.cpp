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

bool valid(int &i, int &j, int &n, int &m) {
    if (min(i, j) < 0 || i >= n || j >= m) {
        return false;
    }
    return true;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (2, false)));
    for (auto &row : grid) {
        cin >> row;
    }
    array<char, 2> closed = {'x', 'o'};
    queue<array<int, 4>> q; //{i, j, state, dis}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                q.push({i, j, 0, 0});
                vis[i][j][0] = true;
            }
        }
    }
    vector<vector<int>> dxy = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    while (q.size()) {
        array<int, 4> cur = q.front();
        q.pop();
        int i = cur[0], j = cur[1], s = cur[2], dis = cur[3];
        if (grid[i][j] == 'G') {
            cout << dis;
            return;
        } else if (grid[i][j] == '?') {
            s ^= 1;
        }
        for (auto d : dxy) {
            int dx = i + d[0], dy = j + d[1];
            if (valid(dx, dy, n, m) && !vis[dx][dy][s] && grid[dx][dy] != '#' && grid[dx][dy] != closed[s]) {
                vis[dx][dy][s] = true;
                q.push({dx, dy, s, dis + 1});
            }
        }
    }
    cout << "-1";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}