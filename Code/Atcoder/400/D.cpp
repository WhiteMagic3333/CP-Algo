#include <queue>
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

vector<array<int, 2>> dxy = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool valid(int &i, int &j, vector<vector<bool>> &vis) {
    if (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]) {
        return true;
    }
    return false;
}
 
void solve()
{
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m));
    for (auto &row : grid) {
        cin >> row;
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    priority_queue<array<int, 3>> pq;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    vector<vector<int>> kicks(n, vector<int> (m, 0));
    pq.push({0, sx, sy});
    while (pq.size()) {
        int _moves = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if (vis[x][y]) {
            continue;
        }
        vis[x][y] = true;
        kicks[x][y] = _moves;
        for (auto d : dxy) {
            int dx = d[0] + x;
            int dy = d[1] + y;
            if (valid(dx, dy, vis)) {
                if (grid[dx][dy] == '.') {
                    pq.push({_moves, dx, dy});
                } else {
                    int ddx = dx + d[0];
                    int ddy = dy + d[1];
                    pq.push({_moves - 1, dx, dy});
                    if (valid(ddx, ddy, vis)) {
                        int cur_moves = _moves - (grid[ddx][ddy] == '#');
                        pq.push({_moves - 1, ddx, ddy});
                    }
                }
            }
        }
    }
    cout << kicks[ex][ey] * -1;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}