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

ll lcm (ll a, ll b) {
    return (a * b) / (__gcd(a, b));
}

ll lcm (ll a, ll b, ll c) {
    return lcm(lcm(a, b), c);
}
 
void solve()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    //principle of inclusion
    ll a_alone = m / a;
    ll b_alone = m / b;
    ll c_alone = m / c;
    ll abc = m / (lcm(a, b, c));
    ll ab = m / (lcm(a, b)) - abc;
    ll bc = m / (lcm(b, c)) - abc;
    ll ac = m / (lcm(a, c)) - abc;
    a_alone = a_alone - ab - ac - abc;
    b_alone = b_alone - ab - bc - abc;
    c_alone = c_alone - bc - ac - abc;
    a = a_alone * 6 + (ab + ac) * 3 + 2 * abc;
    b = b_alone * 6 + (ab + bc) * 3 + 2 * abc;
    c = c_alone * 6 + (bc + ac) * 3 + 2 * abc;
    cout << a << " " << b << " " << c;
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