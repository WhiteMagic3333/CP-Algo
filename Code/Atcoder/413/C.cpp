#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
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
    int q;
    cin >> q;
    queue<pair<ll, ll>> line;
    ll ans;
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            ll c, x;
            cin >> c >> x;
            line.push({c, x});
        } else if (ch == 2) {
            ll k;
            cin >> k;
            ans = 0;
            while (k > 0) {
                pair<ll, ll> f = line.front();
                ll times = min(k, f.first);
                k -= times;
                ans += f.second * times;
                line.front().first -= times;
                if (line.front().first == 0) {
                    line.pop();
                }
            }
            cout << ans << "\n";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}