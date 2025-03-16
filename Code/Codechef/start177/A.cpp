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
    ll x, y, k;
    cin >> x >> y >> k;
    ll ans = 15;
    for (ll i = 0; i <= y; i++) {
        ll x1 = x + i;
        ll y1 = y - i;
        ll diff = abs(x1 - y1);
        if (diff == k) {
            ans = min(ans, i);
        }
    }
    for (ll i = 0; i <= x; i++) {
        ll x1 = x - i;
        ll y1 = y + i;
        ll diff = abs(x1 - y1);
        if (diff == k) {
            ans = min(ans, i);
        }
    }
    if (ans == 15) {
        ans = -1;
    }
    cout << ans;
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