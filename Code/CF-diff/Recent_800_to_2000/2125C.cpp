#include <algorithm>
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

ll fun(ll n) {
    //took around 25 mins
    //2 3 5 7
    //cnt = pa 
    vector<ll> primes = {2, 3, 5, 7};
    //sub even add odd
    int mx = 1 << 4;
    ll ans = 0;
    for (int mask = 1; mask < mx; mask++) {
        ll cur = 1;
        ll cnt = 0;
        for (int i = 0; i < 4; i++) {
            if ((1 << i) & mask) {
                cur *= primes[i];
                cnt++;
            }
        }
        if (cnt % 2) {
            ans += (n / cur);
        } else {
            ans -= (n / cur);
        }
    }
    return n - ans;
}
 
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << fun(r) - fun(l - 1);
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