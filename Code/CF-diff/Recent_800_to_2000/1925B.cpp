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
{   //i did n / x instead of x / n and got wa
    //12 mins to 15 mins instead
    ll x, n;
    cin >> x >> n;
    //(x - factor * (n - 1)) % factor == 0
    if (x % n == 0) {
        cout << x / n;
        return;
    }
    // gcd, gcd, gcd, gcd, gcd * something
    int ans = 1;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            int f = i, s = x / i;
            if ((x / f) >= n) {
                ans = max(ans, f);
            }
            if ((x / s) >= n) {
                ans = max(ans, s);
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