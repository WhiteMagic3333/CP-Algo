#include <numeric>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 998244353
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<long long> a(n + 1), b(m + 1, 0);
    vector<long long> pref_a(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref_a[i] = (pref_a[i - 1] + a[i]) % mod;
    }

    ll sum_b = 0;
    for (int j = 1; j <= m; j++) {
        cin >> b[j];
    }

    sum_b = accumulate(b.begin(), b.end(), 0LL) % mod;

    ll s1 = 0;
    for (ll i = 1; i <= n; i++) {
        s1 = (s1 + i * a[i]) % mod;
    }
    s1 = (s1 * sum_b) % mod;

    ll s2 = 0;
    ll limit = min(n, m);
    
    for (ll j = 1; j <= limit; j++) {
        ll p_j = 0;
        
        for (ll k = 1; k * j <= n; k++) {
            p_j = (p_j + pref_a[n] - pref_a[k * j - 1] + mod) % mod;
        }
        
        ll term = (b[j] * j) % mod;
        s2 = (s2 + term * p_j) % mod;
    }

    ll ans = (s1 - s2 + mod) % mod;
    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}