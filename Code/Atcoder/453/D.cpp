#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <array>
#include <queue>
#include <algorithm>
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
    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                si = i, sj = j;
            } else if (grid[i][j] == 'G') {
                ei = i, ej = j;
            }
        }
    }

    vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool>(5, false)));
    vector<vector<vector<int>>> prev_d(n, vector<vector<int>> (m, vector<int>(5, -1))); 
    
    queue<array<int, 3>> q;
    q.push({si, sj, 4});
    vis[si][sj][4] = true;
    
    vector<array<int, 2>> dxy = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}}; //LRUD
    
    int final_dir = -1;

    while (q.size()) {
        array<int, 3> cur = q.front();
        q.pop();
        int x = cur[0], y = cur[1], dir = cur[2];

        if (x == ei && y == ej) {
            final_dir = dir;
            break;
        }

        for (int k = 0; k < 4; k++) {
            if (grid[x][y] == 'o' && dir != 4 && k != dir) continue;
            
            if (grid[x][y] == 'x' && dir != 4 && k == dir) continue;

            int dx = x + dxy[k][0], dy = y + dxy[k][1];
            
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] != '#') {
                if (!vis[dx][dy][k]) {
                    vis[dx][dy][k] = true;
                    prev_d[dx][dy][k] = dir;
                    q.push({dx, dy, k});
                }
            }
        }
    }

    if (final_dir == -1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    string _dir = "LRUD";
    string ans = "";
    
    int cx = ei, cy = ej, cdir = final_dir;
    
    while (cdir != 4) {
        ans += _dir[cdir];
        int pd = prev_d[cx][cy][cdir];
        
        cx -= dxy[cdir][0];
        cy -= dxy[cdir][1];
        
        cdir = pd;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}