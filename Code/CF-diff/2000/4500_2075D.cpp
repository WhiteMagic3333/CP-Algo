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

int mx_pow = 62;
ll inf = 1e18;

vector<vector<ll>> dp(mx_pow, vector<ll> (mx_pow, inf));

void pre() {
    //dp[k][i][j] is min cost (ie sum of powers of 2) st the max power is k
    //since the max power for this problem is 61 we can use dp[i][j];
    dp[0][0] = 0; //if both are equal the cost is 0
    for (int p = 0; p < mx_pow; p++) {
        for (int i = mx_pow - 1; i >= 0; i--) {
            for (int j = mx_pow - 1; j >= 0; j--) {
                if (dp[i][j] == inf) {
                    continue;
                }
                if (j + p < mx_pow) {
                    dp[i][j + p] = min(dp[i][j + p], dp[i][j] + (1LL << p));
                }
                if (i + p < mx_pow) {
                    dp[i + p][j] = min(dp[i + p][j], dp[i][j] + (1LL << p));
                }
            }
        }
    }

}

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll ans = inf;
    for (int i = 0; i < mx_pow; i++) {
        for (int j = 0; j < mx_pow; j++) {
            if ((x >> i) == (y >> j)) {
                ans = min(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}