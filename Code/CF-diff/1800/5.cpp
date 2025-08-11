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
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> dp(n, vector<int> (5, 2e5));
    // dp[i][j] 
    // dp[i][0] -> top and first half
    // dp[i][1] -> top and second half
    // dp[i][2] -> bottom and first half
    // dp[i][3] -> bottom and second half
    // dp[i][4] -> row selected
    dp[0][4] = a[0] > 0;
    if (a[0] < 3 && a[0] > 0) {
        dp[0][2] = dp[0][4];
    }
    int mn = dp[0][4];
    // cout << dp[0];
    for (int i = 1; i < n; i++) {
        dp[i][4] = dp[i - 1][4] + (a[i] > 0);

        if (a[i]) {
            if (a[i] < 3) {
                dp[i][0] = dp[i - 1][2];
                dp[i][2] = dp[i - 1][4] + 1;
                dp[i][4] = min(dp[i][4], dp[i][0]);
            } else if (a[i] < 5) {
                dp[i][2] = dp[i - 1][3] + 1;
                dp[i][3] = dp[i - 1][2] + 1;
            }
        }
        // cout << dp[i];
    }
    cout << *min_element(dp.back().begin(), dp.back().end());
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