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

vector<vector<int>> dxy = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int n, m;

bool check(vector<string> &grid, int i, int j) {
    int cnt = 0;
    for (auto d : dxy) {
        int dx = d[0] + i, dy = d[1] + j;
        if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
            cnt += grid[dx][dy] == '#';
        }
    }
    return cnt == 2 || cnt == 4;
}
 
void solve()
{
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#' && !check(grid, i, j)) {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}