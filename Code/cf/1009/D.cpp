#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <map>
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

ll dis_sq(ll x, ll &y) {
    return (x * x) + (y * y);
}

ll height(ll &x, ll &x2, ll &r) {
    ll low = 0, high = 1e9;
    ll ans = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (dis_sq(x - x2, mid) <= (r * r)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    map<ll, ll> s;
    vector<ll> c(n), r(n);
    cin >> c >> r;
    for (int i = 0; i < n; i++) {
        for (ll j = c[i] - r[i]; j <= c[i] + r[i]; j++) {
            s[j] = max(s[j], 2 * height(j, c[i], r[i]) + 1);
        }
    }
    for (auto &cur : s) {
        ans += cur.second;
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