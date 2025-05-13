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
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    vector<vector<bool>> row_vis(n, vector<bool> (n + 2, false));
    for (int i = 0; i < n; i++) {
        vector<bool> col_vis(n + 2, false);
        int col_mex = 0;
        for (int j = 0; j < n; j++) {
            int row_mex = 0;
            while (row_vis[j][row_mex]) {
                row_mex++;
            }
            int mex = min(col_mex, row_mex);
            row_vis[j][mex] = col_vis[mex] = true;
            grid[i][j] = mex;
            while (col_vis[col_mex]) {
                col_mex++;
            }
        }
    }
    for (auto &row : grid) {
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