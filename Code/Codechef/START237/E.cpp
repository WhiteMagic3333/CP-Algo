#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
vector<bool> prime;
const ll mod = 998244353;
 
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
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> dp(m, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        vector<long long> dp2(m, 0);
        
        long long sum = 0;
        for (auto j : dp) {
            sum += j;
            sum %= mod;
        }
        dp2[0] = sum;

        for (int j = 0; j < m; ++j) {
            if (dp[j] == 0) {
                continue;
            }

            dp2[j] = (dp2[j] + dp[j] * (j + n - m)) % mod;

            if (j + 1 < m) {
                dp2[j + 1] = (dp2[j + 1] + dp[j] * (m - j)) % mod;
            }
        }
        dp = dp2;
    }

    ll ans = 0;
    for (auto j : dp) {
        ans += j;
        ans %= mod;
    }
    cout << ans ;
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