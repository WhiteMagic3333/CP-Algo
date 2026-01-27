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
    vector<vector<ll>> dp(n + 1, vector<ll> (w + 1, 0));
    dp[0][0] = 0;
    vector<vector<ll>> arr(n, vector<ll> (2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int idx = i - 1;
        for (int j = arr[idx][0]; j <= w; j++) {
            dp[i][j] = max({dp[i][j], dp[i - 1][j - arr[idx][0]] + arr[idx][1], dp[i][j - 1]});
        }
    }
    cout << dp[n][w];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}