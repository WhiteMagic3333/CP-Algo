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

ll lcd(ll a, ll b) {
    ll g = __gcd(a, b);
    return  (a * b) / g;
}
 
void solve()
{
    //if gcd(a, b, c) = gcd(gcd(a, b), gcd(b, c))
    //so as long as we keep the gcd of pairs equal we are good to m
    //now middle no is imp

    // gcd(a, b) = g1
    // gcd(b, c) = g2
    //so can we update b
    // the border elements can sure be updated
    //23 mins out of pracctise
    //didnt prove wasnt clear as well
    //wasnt confident as well
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    int g1 = __gcd(a[0], a[1]);
    int g2 = __gcd(a[n - 1], a[n - 2]);
    int ans = 0;
    if (g1 != a[0]) {
        ans++;
        a[0] = g1;
    }
    if (g2 != a[n - 1]) {
        ans++;
        a[n - 1] = g2;
    }
    for (int i = n - 2; i > 0; i--) {
        //we have to pick the middle such that
        // __gcd(prev, cur) is same and __gcd(cur, next) is also the same
        // so lcm of both gcd should give us cur
        g1 = __gcd(a[i - 1], a[i]);
        g2 = __gcd(a[i + 1], a[i]);
        ll l = lcm(g1, g2);
        if (l < a[i]) {
            ans++;
            a[i] = l;
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