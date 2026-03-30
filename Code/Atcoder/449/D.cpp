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

ll get(ll l, ll r, ll abs_x) {
    //i from l to r where abs(i) < abs_x
    if (abs_x == 0) {
        return 0;
    }
    ll ans = 0;
    if (l <= 0 && r >= 0) {
        ans += 1 + min(abs(l), abs_x - 1) + min(r, abs_x - 1);
    } else if (r >= 0 && l >= 0) {
        ans += max(0LL, min(r, abs_x - 1) - l + 1);
    } else if (r <= 0 && l <= 0) {
        ans += max(0LL, min(abs(l), abs_x - 1) - abs(r) + 1);
    }
    return ans;
}
 
void solve()
{
    ll l, r, d, u;
    cin >> l >> r >> d >> u;
    ll ans = 0;
    //case three x == y and both are even
    ll mn = min(r, u);
    if (abs(mn) % 2) {
        mn--;
    }
    ll mx = max(l, d);
    for (ll i = l; i <= r; i++) {
        if (abs(i) % 2 == 0) {
            if (i <= u && i >= d) {
                ans++;
            }
            if ((-i) <= u && (-i) >= d && i != 0) {
                ans++;
            }
        }
    }
    // cout << ans << " ";
    //case two y > x
    ll y = u;
    if (abs(y) % 2) {
        y--;
    }
    for (ll i = y; i >= d; i -= 2) {
        //find all abs(x) < abs(y)
        ans += get(l, r, abs(i));
    }

    // case one x > y
    ll x = r;
    if (abs(x) % 2) {
        x--;
    }
    for (ll i = x; i >= l; i -= 2) {
        //find all abs(x) < abs(y)
        ans += get(d, u, abs(i));
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}