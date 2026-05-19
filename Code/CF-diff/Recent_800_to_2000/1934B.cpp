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

vector<ll> dp(100, 1e9);

void pre() {
    dp[1] = dp[3] = dp[6] = dp[10] = dp[15] = 1;
    dp[0] = 0;
    for (int i = 1; i < 100; i++) {
        for (int j = i; j >= 1; j--) {
            if (dp[j] == 1) {
                dp[i] = min(dp[i], i / j + dp[i % j]);
                dp[i] = min(dp[i], i / j - 1 + dp[i % j + j]);
            }
        }
    }
}
 
void solve()
{   //18 mins too long
    //1 3 6 10 15
    //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    //1 2 1 2 3 1 2 3 2 1   2  2  2  3  1
    ll n;
    cin >> n;
    ll ans = n;
    for (int j = 15; j >= 1; j--) {
        if (dp[j] == 1) {
            ans = min(ans, n / j + dp[n % j]);
            if (n >= 2 * j) {
                ans = min(ans, n / j - 1 + dp[n % j + j]);
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