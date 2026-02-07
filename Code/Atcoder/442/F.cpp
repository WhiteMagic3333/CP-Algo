#include <algorithm>
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
    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }
    vector<vector<ll>> balance(n + 1, vector<ll> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        int black = count(grid[i].begin(), grid[i].end(), '#');
        int l_black = 0;
        balance[i + 1][0] = n - black;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                l_black++;
            }
            balance[i + 1][j + 1] = l_black + (n - (black - l_black) - j - 1);
        }
    }
    cout << balance[n];
    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 1e18));
    //dp[i][j] = all elements on the left of j 
    //till j is white on the i'th row and below are balanced
    dp[n] = balance[n];
    for (int i = n - 1; i > 0; i--) {
        ll mn = dp[i + 1][0];
        for (int j = 0; j <= n; j++) {
            mn = min(mn, dp[i + 1][j]);
            dp[i][j] = balance[i][j] + mn;
        }
    }
    cout << *min_element(dp[1].begin(), dp[1].end());
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}