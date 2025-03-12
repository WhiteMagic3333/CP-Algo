#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <bitset>
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
    ll x;
    cin >> x;
    bitset<32> cur(x);
    ll pre = x&(x - 1);
    ll suf = x&(x + 1);
    if (pre == 0 || suf == 0) {
        cout << "-1";
        return;
    }
    for (ll i = 1; i <= 32; i++) {
        ll prev = (1LL << (i - 1));
        ll cur = (1LL << (i));
        bool prev_x = (prev&x);
        bool cur_x = (cur&x);
        if (prev_x != cur_x) {
            ll ans = prev + cur;
            // cout << x << " ";
            cout << ans;
            // ll other = x ^ ans;
            // cout << " " << other;
            // if ((x + other) > ans && (x + ans) > other && (other + ans) > x) {
                // cout << "yesr";
            // }
            return;
        }
    }
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