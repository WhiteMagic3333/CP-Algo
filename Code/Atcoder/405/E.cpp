#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
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

ll mod = 998244353;
vector<ll> fac(4e6 + 1), inv_fac(4e6 + 1);

long long power(long long x, long long y, long long mod) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

void pre() {
    ll mx = 4e6;
    fac[0] = 1;
    for (ll i = 1; i <= mx; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv_fac[mx] = power(fac[mx], mod - 2, mod);
    for (ll i = mx - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }
}

ll xy(ll a, ll o) {
    ll ao = fac[a + o] * inv_fac[a];
    ao %= mod;
    ao *= inv_fac[o];
    ao %= mod;
    return ao;
}
 
void solve()
{
    ll a, o, b, g;
    cin >> a >> o >> b >> g;
    //a is before b
    //a is before g
    //o is before g
    //.. a .. b ..
    //.. a .. g ..
    //.. o .. g ..
    // aobg.
    // aogb
    // abog
    // oabg.
    // oagb
    // (ao)(bg) = aobg, oabg, aogb, oagb
    // sahi yha tak
    // 





    // a(ob)g = aobg, abog - 1(extra)
    ll ans = -1;//to remove extra abog
    // (ao)(bg)
    ll ao = xy(a, o);
    ll bg = xy(b, g);
    ans += (ao * bg);
    for (ll i = 0; i < o; i++) {
        //i' oranages with apples and rest with bananas
        ll rest = o - i;
        ll _ao = xy(a, i), _bo = xy(b, rest);
        ans += _ao * _bo;
        ans %= mod;
    }
    if (ans < 0) {
        ans += mod;
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    solve();
    return 0;
}