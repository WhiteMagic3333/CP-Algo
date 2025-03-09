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
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n), w(m);
    cin >> b >> w;
    sort(b.begin(), b.end(), greater<ll> ());
    sort(w.begin(), w.end(), greater<ll> ());
    ll ans = 0, sum = 0, b_pos = 0, w_pos = 0;
    for (int i = 0; i < n && b[i] > 0; i++) {
        sum += b[i];
        b_pos++;
    }
    for (int i = 0; i < m && w[i] > 0; i++) {
        sum += w[i];
        w_pos++;
    }
    if (b_pos >= w_pos) {
        return void(cout << sum);
    }
    for (int i = 0; i < min(n, m); i++) {
        ans = max(ans, ans + b[i] + w[i]);
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