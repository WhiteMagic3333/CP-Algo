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
    int n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    // vector<ll> dp(n + 1, -1e18);
    vector<vector<ll>> dp(n + 2, vector<ll> (w + 1, -1e18));
    // dp[0] = 0;
    // dp[0][0] = 0;
    // //dp[i] -> max value till ith idx having max weight w
    // for (int i = 1; i <= n; i++) {
    //     int idx = i - 1;
    //     dp[i] = dp[i - 1];
    //     for (int j = 0; j <= w; j++) {
    //        if (j > 0) {
    //             dp[i][j] = max({dp[i][j], dp[i][j - 1]});
    //        }
    //        if (j - weight[idx] >= 0) {
    //             dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[idx]] + value[idx]);
    //        }
    //     }
    // }
    // cout << dp[n][w];
    dp[n + 1][0] = 0;
    for (int i = n; i >= 1; i--) {
        int idx = i - 1;
        dp[i] = dp[i + 1];
        for (int j = 0; j <= w; j++) {
           if (j > 0) {
                dp[i][j] = max({dp[i][j], dp[i][j - 1]});
           }
           if (j - weight[idx] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - weight[idx]] + value[idx]);
           }
        }
    }
    cout << dp[1][w];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}