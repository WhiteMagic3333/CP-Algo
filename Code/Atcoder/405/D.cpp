#include <array>
#include <vector>
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
        std::cout << x;
    std::cout << '\n';
    return out;
}
 
void solve()
{
    //multisource bfs
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m));
    vector<vector<char>> ans(n, vector<char> (m));
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') {
                if (grid[i][j] == 'E') {
                    q.push({i, j});
                }
                vis[i][j] = true;
                ans[i][j] = grid[i][j];
            }
        }
    }
    vector<vector<int>> dxy = {
        {0, 1},//right
        {0, -1},//left
        {1, 0},//down
        {-1, 0}//up
    };
    vector<char> sign = {
        '<',
        '>',
        '^',
        'v',
    };
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = dxy[i][0] + x, dy = dxy[i][1] + y;
            if (min(dx, dy) >= 0 && dx < n && dy < m && !vis[dx][dy]) {
                ans[dx][dy] = sign[i];
                q.push({dx, dy});
                vis[dx][dy] = true;
            }
        }
    }
    for (auto &row : ans) {
        cout << row;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}