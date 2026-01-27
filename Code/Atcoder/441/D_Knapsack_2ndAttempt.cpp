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
    vector<ll> value(n), weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    //try to define dp[i]
    //if it gets complicated add another layer or state
    //dp[i] = is max possible values till i'th index from 0 and
    //having max capacity W
    // vector<vector<ll>> dp(n + 2, vector<ll> (w + 1, -1e18));
    vector<vector<ll>> dp2(n + 2, vector<ll> (w + 1, -1e18));
    // dp[0][0] = 0; //no item and no weight
    // for (int i = 0; i < n; i++) {
    //     int idx = i + 1;
    //     dp[idx] = dp[idx - 1];
    //     for (int j = 1; j <= w; j++) {
    //         dp[idx][j] = max({dp[idx][j], dp[idx - 1][j], dp[idx][j - 1]});
    //         if (j >= weight[i]) {
    //             dp[idx][j] = max(dp[idx][j], dp[idx - 1][j - weight[i]] + value[i]);
    //         }
    //     }
    // }
    // cout << dp[n][w];
    // dp2[n + 1][0] = 0; //dp[i][j] = from n'th element till i'th element having max capacity j
    //               //what is the max value we can achieve
    // for (int i = n - 1; i >= 0; i--) {
    //     int idx = i + 1;
    //     dp2[idx] = dp2[idx + 1];
    //     for (int j = 1; j <= w; j++) {
    //         dp2[idx][j] = max({dp2[idx][j], dp2[idx][j - 1]});
            if (j >= weight[i]) {
                dp2[idx][j] = max(dp2[idx][j], dp2[idx + 1][j - weight[i]] + value[i]);
            }
    //     }
    // }
    // cout << dp2[1][w];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}