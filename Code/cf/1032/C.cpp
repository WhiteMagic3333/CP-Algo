#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
    vector<vector<int>> grid(n, vector<int> (m));
    vector<int> freq(101, 0);
    int mx = 0;
    for (auto &row : grid) {
        for (auto &e : row) {
            cin >> e;
            mx = max(mx, e);
            freq[e]++;
        }
    }
    if (mx > (n + m - 1)) {
        cout << mx;
        return;
    }
    set<int> rows, cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == mx) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    if (rows.size() > 1 && cols.size() > 1) {
        cout << mx;
        return;
    }
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