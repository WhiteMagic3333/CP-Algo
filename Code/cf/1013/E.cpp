#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
vector<int> unique_primes(1e7 + 1, 0);
vector<ll> dp(1e7 + 1, 0);
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * 2; j <= n; j += i){
                prime[j] = false;
                unique_primes[j]++;
            }
        }
    }
    for (ll i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + max(1, unique_primes[i]);
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
    ll n;
    cin >> n;
    cout << dp[n];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve(1e7);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}