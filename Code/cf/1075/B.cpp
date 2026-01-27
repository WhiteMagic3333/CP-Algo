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
{ //read test cases
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll ans = -1;
    ll z = 0;
    // for (int i = 0; i < n; i++) {
    //     ll mx_reach = a[i] * (b[i] - 1);
    //     if ((a[i] * b[i]) <= c[i] && mx_reach < x) {
    //         continue;
    //     }
    //     if (mx_reach >= x) {
    //         ans = 0;
    //         break;
    //     }
    //     ll to_reach = x - mx_reach;
    //     ll div = (a[i] * b[i]) - c[i];
    //     ll steps = to_reach / div + ((to_reach % div) ? 1 : 0);
    //     ans = (ans == -1) ? steps : min(ans, steps);
    // }
    ll mx_per_rollback = -1e18, idx = 0;
    for (int i = 0; i < n; i++) {
        z += a[i] * (b[i] - 1);
        if ((a[i] * b[i] - c[i]) > mx_per_rollback) {
            mx_per_rollback = a[i] * b[i] - c[i];
            idx = i;
        }
    }
    if (z >= x) {
        ans = 0;   
    } else {
        if (mx_per_rollback > 0) {
            z = z - c[idx] + a[idx];
            ans = 1;
            ll reach = a[idx] * (b[idx] - 1);
            ll to_reach = x - z - reach;
            if (to_reach > 0) {
                ll div = (a[idx] * b[idx]) - c[idx];
                ll steps = to_reach / div + ((to_reach % div) ? 1 : 0);
                ans += steps;
            }
        }
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