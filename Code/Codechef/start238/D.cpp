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

ll calc(ll x, ll y, ll k, ll h) {
    if (x >= y) 
        return (x - y) * k;
    
    while (1) {
        ll lsb = x & -x;
        if (x + lsb <= y) {
            x += lsb;
        } else {
            break;
        }
    }
    
    if (x == y) 
        return 0;
    
    ll nx = x + (x & -x);
    ll cost_A = (nx - y) * k;
    ll cost_B = h + calc(x + 1, y, k, h);
    
    return min(cost_A, cost_B);
}
 
void solve() {
    ll n, k, h;
    cin >> n >> k >> h;
    
    vector<ll> a(n);
    cin >> a;
    
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += calc(a[i], a[i+1], k, h);
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