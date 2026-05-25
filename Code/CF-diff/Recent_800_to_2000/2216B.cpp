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
    //t and u uses 3 x 3
    //t and h uses 5 x 3
    //h and u uses 2 of 3 * 3
    ll t, h, u;
    cin >> t >> h >> u;
    ll mn = min(t, u);
    ll ans = mn * 4;
    t -= mn;
    u -= mn;
    if (t == 2 && h) {
        ans += 7;
        t = 0, h = 0;
    } else if (t == 1 && h) {
        ans += 5;
        t--;
        h--;
    }
    ans += (t > 0 ? (t * 2 + 1) : 0) + h * 3 + u * 3;
    //t is odd, t is even, h is odd, h is even
    //T
    //H
    //T is 
    // if (t % 2 && h) {
    //     ans += 5;
    //     h--;
    //     t--;
    // }
    // ans += (t % 2 ? 3 : 0) + (t / 2) * 5;
    // t = 0;
    // ans += t * 3 + h * 3 + u * 3;
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