#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
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
    ll mod = 998244353;
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<ll>> dp(n, vector<ll> (3, 0));
    dp[0][str[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
        int idx = str[i] - 'a';
        dp[i] = dp[i - 1];
        dp[i][idx] += 1;
        dp[i][idx] %= mod;
        for (int j = 0; j < 3; j++) {
            if (j == idx) {
                continue;
            }
            dp[i][idx] += dp[i - 1][j];
            dp[i][idx] %= mod;
        }
    }
    ll ans = 0;
    for (auto e : dp[n - 1]) {
        ans += e;
        ans %= mod;
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}