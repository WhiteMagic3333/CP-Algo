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
    inv_fac[mx] = power(fac[mx], mod - 2, mod); //fermats little theorem here
    for (ll i = mx - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod; // ((40)!)^-1 * 40
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
    ll n = a + o + b + g;
    // for now when ever there is bionomial expo instead
    // use Kohli G's formulae for fac and inv_fac
    // lets say we have 3 apples and 2 oranges and we have to count all ways(arrangements), eg
    // AAAOO, AAOAO and so on toh ham, esa karte the
    // (3 + 2)! / (3!).(2!)
    // atleast school me toh ese hi samjhaya tha
    // but many people also use binomial coefficient for this which I cant understand
    // as per gpt tho, it says instead of picking apples we try and pick slots, like choose 3 out of 5 slots for apple or choose 2 out of 5 slots for orange (both will be same)
    // 5C2 or 5C3 which makes sense but is not intuitive

    



    // a before b and g
    // o before g


    // _ _ _ _ _ ....  _        _ _ _ _ _ _
       // 1 2     a'th   (a + oth)


    // oranges  grapes
    // total C banana


    // so last apple can be from a to (a + o)
    // after this with the remaining oranges
    // last orange can be from o' to (o' + b)
    // after this let b' banana remains so (b' + g)

 
    ll f_ans = 0;
    for (ll i = 0; i <= o; i++) {
        // (a - 1) apples & i oranges
        ll ans = 1;
        ans *= (fac[a - 1 + i]);
        ans %= mod;
        ans *= inv_fac[a - 1];
        ans %= mod;
        ans *= inv_fac[i];
        ans %= mod;
        // in the remaining positions we can fill b
        ll rem = n - i - a;
        ans *= fac[rem];
        ans %= mod;
        ans *= inv_fac[b];
        ans %= mod;
        ans *= inv_fac[rem - b];
        ans %= mod;
        f_ans += ans;
        f_ans %= mod;
    }
    cout << f_ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    solve();
    return 0;
}


// lets say we have 3 apples A and 2 oranges O and we have to count all ways(arrangements), eg
// AAAOO, AAOAO and so on toh ham, esa karte the

(5!) / (3!.2!)

-> arrange 3 items A and 2 items O together

5C3 -> select 2 out of 5


we need 3 postions from 5
_ _ _ _ _

5C3




given 3 Apples and 2 orrange, 2 banana count arrangements


7! / (3! . 2! . 2!)

7C3 . 4C2 . 2C2 (using remaining positions)

_ _ _ _ _ _ _ 